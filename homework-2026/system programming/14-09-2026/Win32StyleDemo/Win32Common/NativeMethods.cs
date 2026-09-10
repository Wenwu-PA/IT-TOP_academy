using System;
using System.Runtime.InteropServices;
using System.Text;

namespace Win32Common
{
    public delegate bool EnumChildProc(IntPtr hWnd, IntPtr lParam);

    public static class NativeMethods
    {
        [DllImport("user32.dll", SetLastError = true)]
        public static extern IntPtr FindWindow(string lpClassName, string lpWindowName);

        [DllImport("user32.dll")]
        public static extern bool EnumChildWindows(IntPtr hWndParent, EnumChildProc lpEnumFunc, IntPtr lParam);

        [DllImport("user32.dll", CharSet = CharSet.Auto)]
        public static extern int GetClassName(IntPtr hWnd, StringBuilder lpClassName, int nMaxCount);

        [DllImport("user32.dll", CharSet = CharSet.Auto)]
        public static extern int GetWindowText(IntPtr hWnd, StringBuilder lpString, int nMaxCount);

        [DllImport("user32.dll", SetLastError = true)]
        public static extern IntPtr GetWindowLongPtr(IntPtr hWnd, int nIndex);

        [DllImport("user32.dll", SetLastError = true)]
        public static extern IntPtr SetWindowLongPtr(IntPtr hWnd, int nIndex, IntPtr dwNewLong);

        [DllImport("user32.dll")]
        public static extern bool SetWindowPos(IntPtr hWnd, IntPtr hWndInsertAfter, int X, int Y, int cx, int cy, uint uFlags);

        [DllImport("user32.dll")]
        public static extern bool InvalidateRect(IntPtr hWnd, IntPtr lpRect, bool bErase);

        [DllImport("user32.dll")]
        public static extern bool UpdateWindow(IntPtr hWnd);

        [DllImport("user32.dll")]
        public static extern IntPtr SendMessage(IntPtr hWnd, uint Msg, IntPtr wParam, IntPtr lParam);

        public const int GWL_STYLE = -16;
        public const int GWL_EXSTYLE = -20;

        public const uint WS_CHILD = 0x40000000;
        public const uint WS_VISIBLE = 0x10000000;
        public const uint WS_BORDER = 0x00800000;
        public const uint WS_DLGFRAME = 0x00400000;
        public const uint WS_THICKFRAME = 0x00040000;
        public const uint ES_MULTILINE = 0x0004;
        public const uint ES_AUTOVSCROLL = 0x0040;
        public const uint ES_AUTOHSCROLL = 0x0080;
        public const uint BS_OWNERDRAW = 0x0000000B;
        public const uint BS_PUSHBUTTON = 0x00000000;

        public const uint WS_EX_CLIENTEDGE = 0x00000200;
        public const uint WS_EX_STATICEDGE = 0x00020000;
        public const uint WS_EX_DLGMODALFRAME = 0x00000001;

        public const uint SWP_NOMOVE = 0x0002;
        public const uint SWP_NOSIZE = 0x0001;
        public const uint SWP_NOZORDER = 0x0004;
        public const uint SWP_FRAMECHANGED = 0x0020;

        public const uint WM_SETFONT = 0x0030;
        public const uint WM_GETFONT = 0x0031;
        public const uint WM_SETREDRAW = 0x000B;

        public static string GetWindowText(IntPtr hWnd)
        {
            var sb = new StringBuilder(256);
            GetWindowText(hWnd, sb, sb.Capacity);
            return sb.ToString();
        }

        public static string GetClassName(IntPtr hWnd)
        {
            var sb = new StringBuilder(256);
            GetClassName(hWnd, sb, sb.Capacity);
            return sb.ToString();
        }

        public static void ModifyStyle(IntPtr hWnd, uint styleToAdd, uint styleToRemove, bool isExStyle = false)
        {
            int index = isExStyle ? GWL_EXSTYLE : GWL_STYLE;
            IntPtr currentStylePtr = GetWindowLongPtr(hWnd, index);
            uint currentStyle = unchecked((uint)currentStylePtr.ToInt64());
            currentStyle |= styleToAdd;
            currentStyle &= ~styleToRemove;
            SetWindowLongPtr(hWnd, index, new IntPtr(unchecked((int)currentStyle)));
            SetWindowPos(hWnd, IntPtr.Zero, 0, 0, 0, 0,
                SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
            InvalidateRect(hWnd, IntPtr.Zero, true);
            UpdateWindow(hWnd);
        }
    }

    public class ChildWindowInfo
    {
        public IntPtr Handle { get; set; }
        public string ClassName { get; set; } = string.Empty;
        public string Text { get; set; } = string.Empty;
    }
}