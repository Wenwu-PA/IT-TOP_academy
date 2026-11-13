#pragma once

#include <iostream>
#include <string>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
using SocketHandle = SOCKET;
constexpr SocketHandle InvalidSocket = INVALID_SOCKET;
#else
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
using SocketHandle = int;
constexpr SocketHandle InvalidSocket = -1;
#endif

constexpr int MAXSTRLEN = 255;

class Socket
{
protected:
    SocketHandle skt = InvalidSocket;
    sockaddr_in addr{};
public:
    Socket();
    ~Socket();
    Socket(const Socket&) = delete;
    Socket& operator=(const Socket&) = delete;
    bool SendData(const char* buffer);
    bool ReceiveData(char* buffer, int size);
    void CloseConnection();
    bool SendDataMessage();
};

class ServerSocket : public Socket
{
public:
    void Bind(int port);
    void Listen();
    void StartHosting(int port);
};

class ClientSocket : public Socket
{
public:
    void ConnectToServer(const char* ip, int port);
};
