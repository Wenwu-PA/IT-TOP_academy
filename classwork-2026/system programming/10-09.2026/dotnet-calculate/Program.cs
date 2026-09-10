using System.Diagnostics;

// Process proc = new Process();
// proc.StartInfo.FileName = "notepad.exe";
// proc.Start();
// Console.WriteLine("Starting proccess " + proc.ProcessName);
// proc.WaitForExit();

// Console.WriteLine("Proccess ending " + proc.ExitCode);
// Console.WriteLine("Name current proccess: " + Process.GetCurrentProcess().ProcessName);


Process proc = new Process();
proc.StartInfo.FileName = "mspaint.exe";
proc.Start();
Console.WriteLine("Starting proccess " + proc.ProcessName);
proc.WaitForExit();

Console.WriteLine("Proccess ending " + proc.ExitCode);
Console.WriteLine("Name current proccess: " + Process.GetCurrentProcess().ProcessName);