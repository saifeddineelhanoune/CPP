#include "Server.hpp"

Server::Server() {

}

Server::Server(int port) {
    _sockFd = socket(AF_INET, SOCK_STREAM, 0);
    if (_sockFd < 0)
        throw std::runtime_error("Error creating socket.\n");
    //server address structure
    _serverAddr.sin_family = AF_INET;
    _serverAddr.sin_addr.s_addr = INADDR_ANY;
    _serverAddr.sin_port = htons(port);
    //Bind socket
    if (bind(_sockFd, (struct sockaddr*)&_serverAddr, sizeof(_serverAddr)) < 0)
        throw std::runtime_error("Error Binding socket");
    //Start listening
    listen(_sockFd, 10);
    setNonBlocking();
    std::cout << "server started on port :" << port << std::endl;
}

void    Server::acceptClients() {
    while (true) {
        struct sockaddr_in clientAddr;
        socklen_t clientLen = sizeof(clientAddr);
        int clientSock = accept(_sockFd, (struct sockaddr*)&clientAddr, &clientLen);
        if (clientSock < 0) {
            if (errno == EWOULDBLOCK || errno == EAGAIN)
                break;
            else
                throw std::runtime_error("Error accepting client connection.");
        } else {
            _clients.push_back(new Client());
            std::cout << "Client connected." << std::endl;
        }
    }
}

