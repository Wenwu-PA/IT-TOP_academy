#include "socket.h"

#include <cerrno>
#include <cstring>
#include <stdexcept>

namespace
{
void CloseSocket(SocketHandle handle)
{
#ifdef _WIN32
    closesocket(handle);
#else
    close(handle);
#endif
}

bool Interrupted()
{
#ifdef _WIN32
    return WSAGetLastError() == WSAEINTR;
#else
    return errno == EINTR;
#endif
}
}

Socket::Socket()
{
#ifdef _WIN32
    WSADATA data{};
    if (WSAStartup(MAKEWORD(2, 2), &data) != 0)
        throw std::runtime_error("Не удалось инициализировать WinSock");
#endif
    skt = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (skt == InvalidSocket)
    {
#ifdef _WIN32
        WSACleanup();
#endif
        throw std::runtime_error("Не удалось создать сокет");
    }
}

Socket::~Socket()
{
    CloseConnection();
#ifdef _WIN32
    WSACleanup();
#endif
}

bool Socket::SendData(const char* buffer)
{
    // Нулевая граница сообщения позволяет корректно читать поток TCP.
    const auto length = std::strlen(buffer) + 1;
    std::size_t sent = 0;
    while (sent < length)
    {
        int flags = 0;
#ifdef MSG_NOSIGNAL
        flags = MSG_NOSIGNAL;
#endif
#ifdef SO_NOSIGPIPE
        const int enabled = 1;
        if (setsockopt(skt, SOL_SOCKET, SO_NOSIGPIPE,
                       reinterpret_cast<const char*>(&enabled), sizeof(enabled)) != 0)
            return false;
#endif
        const auto count = send(skt, buffer + sent,
                                static_cast<int>(length - sent), flags);
        if (count < 0 && Interrupted())
            continue;
        if (count <= 0)
            return false;
        sent += static_cast<std::size_t>(count);
    }
    return true;
}

bool Socket::ReceiveData(char* buffer, int size)
{
    if (size <= 0)
        return false;
    buffer[0] = '\0';
    int used = 0;
    while (true)
    {
        char character{};
        const auto count = recv(skt, &character, 1, 0);
        if (count < 0 && Interrupted())
            continue;
        if (count <= 0)
            return false;
        if (character == '\0')
            return true;
        if (used >= size - 1)
            return false;
        buffer[used++] = character;
        buffer[used] = '\0';
    }
}

void Socket::CloseConnection()
{
    if (skt != InvalidSocket)
    {
        CloseSocket(skt);
        skt = InvalidSocket;
    }
}

bool Socket::SendDataMessage()
{
    std::cout << "Введите сообщение: ";
    std::string message;
    if (!std::getline(std::cin, message))
        return false;
    while (message.size() >= MAXSTRLEN)
    {
        std::cout << "Сообщение должно быть короче " << MAXSTRLEN
                  << " байт. Повторите ввод: ";
        if (!std::getline(std::cin, message))
            return false;
    }
    if (!SendData(message.c_str()))
        return false;
    return message != "end";
}

void ServerSocket::Bind(int port)
{
    const int enabled = 1;
    if (setsockopt(skt, SOL_SOCKET, SO_REUSEADDR,
                   reinterpret_cast<const char*>(&enabled), sizeof(enabled)) != 0)
        throw std::runtime_error("Не удалось настроить сокет");
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(static_cast<unsigned short>(port));
    std::cout << "Привязываю слушающий сокет к порту: " << port << '\n';
    if (bind(skt, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) != 0)
        throw std::runtime_error("Привязка к порту не удалась");
}

void ServerSocket::Listen()
{
    std::cout << "Ожидаю подключения от клиента...\n";
    if (listen(skt, 1) != 0)
        throw std::runtime_error("Ошибка прослушивания");
    SocketHandle connected;
    do
    {
        connected = accept(skt, nullptr, nullptr);
    } while (connected == InvalidSocket && Interrupted());
    if (connected == InvalidSocket)
        throw std::runtime_error("Не удалось принять подключение");
    CloseConnection();
    skt = connected;
}

void ServerSocket::StartHosting(int port)
{
    Bind(port);
    Listen();
}

void ClientSocket::ConnectToServer(const char* ip, int port)
{
    addr.sin_family = AF_INET;
    addr.sin_port = htons(static_cast<unsigned short>(port));
    if (inet_pton(AF_INET, ip, &addr.sin_addr) != 1)
        throw std::runtime_error("Некорректный IPv4-адрес");
    if (connect(skt, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) != 0)
        throw std::runtime_error("Не удалось подключиться к серверу");
}
