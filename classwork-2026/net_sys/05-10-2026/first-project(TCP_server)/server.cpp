#include <iostream>
#include <winsock2.h> // для функций библиотеки WinSock2
#include <ws2tcpip.h> // для функции inet_pton
#include <cstring>    // для функции strlen

#pragma comment(lib, "ws2_32.lib")

int main()
{
    // 1. Инициализировать библиотеку работы с сокетами
    WSADATA wsaData{};
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // 2. Создать сокет
    SOCKET skt{};
    skt = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // 3. Привязать сокет к нужным IP-адресу и порту
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, "0.0.0.0", &addr.sin_addr); // слушает всё и везде
    addr.sin_port = htons(20000);
    bind(skt, reinterpret_cast<sockaddr*>(&addr), sizeof(addr));

    // 4. Установить сокет в режим прослушивания
    listen(skt, 1);
    std::cout << "Сервер запущен и ждет подключений...\n";

    // 5. Принять подключение клиента
    SOCKET acceptSkt{};
    acceptSkt = accept(skt, NULL, NULL);

    // 6. Получить данные от клиента и вывести их в консоль
    const int MAXSTRLEN{ 255 };
    char buf[MAXSTRLEN]{};
    int bytes_recv{};
    bytes_recv = recv(acceptSkt, buf, MAXSTRLEN, 0);
    buf[bytes_recv] = '\0';
    std::cout << buf << '\n';

    // 7. Отправить данные клиенту
    const char* text{ "Hello from server! Привет от сервера!" };
    send(acceptSkt, text, strlen(text), 0);

    // 8. Закрыть сокеты
    closesocket(acceptSkt);
    closesocket(skt);

    // 9. Освободить ресурсы
    WSACleanup();

    return 0;
}