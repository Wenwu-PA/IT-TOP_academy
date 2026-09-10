// StyleChanger/Program.cs
using System;
using System.Collections.Generic;
using Win32Common;

namespace StyleChanger
{
    class Program
    {
        static void Main()
        {
            IntPtr hMain = NativeMethods.FindWindow("MyAppMainWindowClass", null);
            if (hMain == IntPtr.Zero)
                return;

            var children = new List<ChildWindowInfo>();
            NativeMethods.EnumChildWindows(hMain, (hChild, lParam) =>
            {
                children.Add(new ChildWindowInfo
                {
                    Handle = hChild,
                    ClassName = NativeMethods.GetClassName(hChild),
                    Text = NativeMethods.GetWindowText(hChild)
                });
                return true;
            }, IntPtr.Zero);

            foreach (var child in children)
            {
                switch (child.ClassName.ToUpper())
                {
                    case "BUTTON":
                        NativeMethods.ModifyStyle(child.Handle,
                            styleToAdd: NativeMethods.BS_OWNERDRAW,
                            styleToRemove: NativeMethods.BS_PUSHBUTTON | NativeMethods.WS_BORDER);
                        NativeMethods.ModifyStyle(child.Handle,
                            styleToAdd: NativeMethods.WS_EX_STATICEDGE,
                            styleToRemove: 0,
                            isExStyle: true);
                        break;

                    case "EDIT":
                        NativeMethods.ModifyStyle(child.Handle,
                            styleToAdd: NativeMethods.ES_MULTILINE | NativeMethods.ES_AUTOVSCROLL,
                            styleToRemove: NativeMethods.ES_AUTOHSCROLL);
                        NativeMethods.ModifyStyle(child.Handle,
                            styleToAdd: NativeMethods.WS_EX_CLIENTEDGE,
                            styleToRemove: 0,
                            isExStyle: true);
                        break;

                    case "STATIC":
                        NativeMethods.ModifyStyle(child.Handle,
                            styleToAdd: NativeMethods.WS_BORDER,
                            styleToRemove: 0);
                        NativeMethods.ModifyStyle(child.Handle,
                            styleToAdd: NativeMethods.WS_EX_DLGMODALFRAME,
                            styleToRemove: 0,
                            isExStyle: true);
                        break;
                }
            }
        }
    }
}