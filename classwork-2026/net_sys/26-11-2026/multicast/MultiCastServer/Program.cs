
using System.Net;
using System.Net.Sockets;
using System.Text;

Console.OutputEncoding = Encoding.UTF8;

int port = ReadPort();

while (true)
{
    Console.WriteLine("\n=== MULTICAST SERVER ===");
    Console.WriteLine($"Текущий порт: {port}");
    Console.WriteLine("1. Отправить сообщение (127.0.0.1)");
    Console.WriteLine("2. Отправить сообщение (вся локальная сеть)");
    Console.WriteLine("3. Изменить порт");
    Console.WriteLine("0. Выход");
    Console.Write("Выбор: ");

    string? choice = Console.ReadLine();

    switch (choice)
    {
        case "1":
            SendMessage(IPAddress.Loopback, port);
            break;

        case "2":
            SendMessage(IPAddress.Parse("224.5.5.5"), port);
            break;

        case "3":
            port = ReadPort();
            break;

        case "0":
            return;

        default:
            Console.WriteLine("Неверный пункт меню.");
            break;
    }
}

static void SendMessage(IPAddress address, int port)
{
    Console.Write("Введите сообщение: ");
    string? message = Console.ReadLine();

    if (string.IsNullOrWhiteSpace(message))
    {
        Console.WriteLine("Сообщение пустое.");
        return;
    }

    try
    {
        // Для localhost используем 127.0.0.1,
        // для LAN — все доступные сетевые интерфейсы.
        IPAddress localAddress = address.Equals(IPAddress.Loopback)
            ? IPAddress.Loopback
            : IPAddress.Any;

        using var udp = new UdpClient(
            new IPEndPoint(localAddress, 0));

        udp.MulticastLoopback = true;
        udp.Ttl = 1;

        byte[] data = Encoding.UTF8.GetBytes(message);

        udp.Send(data, data.Length,
            new IPEndPoint(address, port));

        Console.WriteLine($"Отправлено на {address}:{port}");
    }
    catch (SocketException ex)
    {
        Console.WriteLine($"Ошибка сети: {ex.Message}");
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
