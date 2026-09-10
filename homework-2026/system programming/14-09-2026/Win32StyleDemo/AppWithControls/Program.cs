using System;
using System.Runtime.InteropServices;
using Win32Common;

namespace AppWithControls
{
    class Program
    {
        const int ID_STATIC = 1001;
        const int ID_EDIT = 1002;
        const int ID_BUTTON = 1003;

        const string MainWindowClass = "MyAppMainWindowClass";
        const string MainWindowTitle = "Приложение с элементами управления";

        delegate IntPtr WndProc(IntPtr hWnd, uint msg, IntPtr wParam, IntPtr lParam);

        [DllImport("user32.dll")]
        static extern IntPtr DefWindowProc(IntPtr hWnd, uint msg, IntPtr wParam, IntPtr lParam);

        [DllImport("user32.dll", SetLastError = true, CharSet = CharSet.Auto)]
        static extern ushort RegisterClassEx(ref WNDCLASSEX lpwcx);

        [DllImport("user32.dll", SetLastError = true, CharSet = CharSet.Auto)]
        static extern IntPtr CreateWindowEx(
            uint dwExStyle, string lpClassName, string lpWindowName, uint dwStyle,
            int x, int y, int nWidth, int nHeight,
            IntPtr hWndParent, IntPtr hMenu, IntPtr hInstance, IntPtr lpParam);

        [DllImport("user32.dll")]
        static extern bool ShowWindow(IntPtr hWnd, int nCmdShow);

        [DllImport("user32.dll")]
        static extern bool UpdateWindow(IntPtr hWnd);

        [DllImport("user32.dll")]
        static extern bool GetMessage(out MSG lpMsg, IntPtr hWnd, uint wMsgFilterMin, uint wMsgFilterMax);

        [DllImport("user32.dll")]
        static extern bool TranslateMessage(ref MSG lpMsg);

        [DllImport("user32.dll")]
        static extern IntPtr DispatchMessage(ref MSG lpMsg);

        [DllImport("user32.dll")]
        static extern void PostQuitMessage(int nExitCode);

        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Auto)]
        struct WNDCLASSEX
        {
            public uint cbSize;
            public uint style;
            public WndProc lpfnWndProc;
            public int cbClsExtra;
            public int cbWndExtra;
            public IntPtr hInstance;
            public IntPtr hIcon;
            public IntPtr hCursor;
            public IntPtr hbrBackground;
            public string lpszMenuName;
            public string lpszClassName;
            public IntPtr hIconSm;
        }

        [StructLayout(LayoutKind.Sequential)]
        struct MSG
        {
            public IntPtr hwnd;
            public uint message;
            public IntPtr wParam;
            public IntPtr lParam;
            public uint time;
            public int pt_x;
            public int pt_y;
        }

        static IntPtr MainWndProc(IntPtr hWnd, uint msg, IntPtr wParam, IntPtr lParam)
        {
            if (msg == 0x0002)
            {
                PostQuitMessage(0);
                return IntPtr.Zero;
            }
            return DefWindowProc(hWnd, msg, wParam, lParam);
        }

        static void Main()
        {
            IntPtr hInstance = Marshal.GetHINSTANCE(typeof(Program).Module);
            var wndClass = new WNDCLASSEX
            {
                cbSize = (uint)Marshal.SizeOf(typeof(WNDCLASSEX)),
                style = 0,
                lpfnWndProc = MainWndProc,
                cbClsExtra = 0,
                cbWndExtra = 0,
                hInstance = hInstance,
                hIcon = IntPtr.Zero,
                hCursor = IntPtr.Zero,
                hbrBackground = (IntPtr)6,
                lpszMenuName = null,
                lpszClassName = MainWindowClass,
                hIconSm = IntPtr.Zero
            };

            RegisterClassEx(ref wndClass);

            IntPtr hWndMain = CreateWindowEx(0, MainWindowClass, MainWindowTitle,
                0x00CF0000, 100, 100, 500, 300,
                IntPtr.Zero, IntPtr.Zero, hInstance, IntPtr.Zero);

            CreateWindowEx(0, "STATIC", "Привет! Это статический текст.",
                0x50000000, 20, 20, 250, 25, hWndMain, (IntPtr)ID_STATIC, hInstance, IntPtr.Zero);
            CreateWindowEx(0x00000200, "EDIT", "Введите текст",
                0x50800000, 20, 60, 250, 25, hWndMain, (IntPtr)ID_EDIT, hInstance, IntPtr.Zero);
            CreateWindowEx(0, "BUTTON", "Нажми меня",
                0x50010000, 20, 110, 120, 30, hWndMain, (IntPtr)ID_BUTTON, hInstance, IntPtr.Zero);

            ShowWindow(hWndMain, 1);
            UpdateWindow(hWndMain);

            MSG msg;
            while (GetMessage(out msg, IntPtr.Zero, 0, 0))
            {
                TranslateMessage(ref msg);
                DispatchMessage(ref msg);
            }
        }
    }
}