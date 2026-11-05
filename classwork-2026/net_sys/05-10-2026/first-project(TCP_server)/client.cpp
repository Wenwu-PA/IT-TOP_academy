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

    // 3. Выполнить подключение к серверу
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr); // локальный сервер
    addr.sin_port = htons(20000);
    connect(skt, reinterpret_cast<sockaddr*>(&addr), sizeof(addr));

    // 4. Отправить данные на сервер
    const int MAXSTRLEN{ 255 };
    char buf[MAXSTRLEN]{};
    const char* text{ "Hello from client! Привет от клиента!" };
    send(skt, text, strlen(text), 0);

    // 5. Получить данные от сервера
    int bytes_recv{};
    bytes_recv = recv(skt, buf, MAXSTRLEN, 0);
    buf[bytes_recv] = '\0';
    std::cout << buf << '\n';

    // 6. Закрыть сокет
    closesocket(skt);

    // 7. Освободить ресурсы
    WSACleanup();

    return 0;
}