
using System.Net;
using System.Net.Sockets;
using System.Text;

Console.OutputEncoding = Encoding.UTF8;

int port = ReadPort();

while (true)
{
    Console.WriteLine("\n=== MULTICAST CLIENT ===");
    Console.WriteLine($"Текущий порт: {port}");
    Console.WriteLine("1. Начать получение сообщений");
    Console.WriteLine("2. Изменить порт");
    Console.WriteLine("0. Выход");
    Console.Write("Выбор: ");

    string? choice = Console.ReadLine();

    switch (choice)
    {
        case "1":
            await StartReceiving(port);
            break;

        case "2":
            port = ReadPort();
            break;

        case "0":
            return;

        default:
            Console.WriteLine("Неверный пункт меню.");
            break;
    }
}

static async Task StartReceiving(int port)
{
    try
    {
        // 0.0.0.0 позволяет принимать сообщения
        // с localhost и сетевых интерфейсов.
        using var udp = new UdpClient(
            new IPEndPoint(IPAddress.Any, port));

        udp.JoinMulticastGroup(IPAddress.Parse("224.5.5.5"));

        using var cts = new CancellationTokenSource();

        Console.WriteLine($"\nПрослушивание UDP-порта {port}");
        Console.WriteLine("Нажмите Enter для остановки.\n");

        Task receiver = ReceiveMessages(udp, cts.Token);

        Console.ReadLine();

        cts.Cancel();
        await receiver;

        Console.WriteLine("Приём остановлен.");
    }
    catch (SocketException ex)
    {
        Console.WriteLine($"Ошибка сети: {ex.Message}");
    }
}

static async Task ReceiveMessages(
    UdpClient udp,
    CancellationToken token)
{
    try
    {
        while (!token.IsCancellationRequested)
        {
            UdpReceiveResult result =
                await udp.ReceiveAsync(token);

            string message =
                Encoding.UTF8.GetString(result.Buffer);

            Console.WriteLine(
                $"[{DateTime.Now:HH:mm:ss}] " +
                $"От {result.RemoteEndPoint}: {message}");
        }
    }
    catch (OperationCanceledException)
    {
        // Приём остановлен пользователем.
    }
}

static int ReadPort()
{
    while (true)
    {
        Console.Write("Введите UDP-порт (1–65535): ");

        if (int.TryParse(Console.ReadLine(), out int port)
            && port >= 1 && port <= 65535)
        {
            return port;
        }

        Console.WriteLine("Некорректный порт.");
    }
}
