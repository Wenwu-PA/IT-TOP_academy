#include "socket.h"

#include <cstring>
#include <exception>
#include <limits>

int main()
{
    std::cout << "1. Запустить сервер (серверная часть)\n"
              << "2. Подключиться к серверу (клиентская часть)\n"
              << "3. Выход\nВведите номер пункта: ";
    int choice{};
    if (!(std::cin >> choice))
        return 1;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    constexpr int port = 24242;
    char message[MAXSTRLEN]{};
    try
    {
        if (choice == 1)
        {
            ServerSocket server;
            server.StartHosting(port);
            while (server.ReceiveData(message, MAXSTRLEN))
            {
                std::cout << "Получено: " << message << '\n';
                if (std::strcmp(message, "end") == 0 || !server.SendDataMessage())
                    break;
            }
        }
        else if (choice == 2)
        {
            std::cout << "Введите IPv4-адрес сервера: ";
            std::string ip;
            if (!std::getline(std::cin, ip))
                return 1;
            ClientSocket client;
            client.ConnectToServer(ip.c_str(), port);
            while (client.SendDataMessage() && client.ReceiveData(message, MAXSTRLEN))
            {
                std::cout << "Получено: " << message << '\n';
                if (std::strcmp(message, "end") == 0)
                    break;
            }
        }
    }
    catch (const std::exception& error)
    {
        std::cerr << "Ошибка: " << error.what() << '\n';
        return 1;
    }
    return 0;
}
