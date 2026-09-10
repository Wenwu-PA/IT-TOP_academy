using System.Diagnostics;

Console.WriteLine("Starting proccess list: ");
Process[] procArr = Process.GetProcesses();
foreach (Process proc in procArr)
{
    Console.WriteLine("|process: " + proc.ProcessName + "| id: " + proc.Id);
}