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

Client*    Server::acceptClients() {
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

void    Server::handleClients() {
        for (std::vector<Client*>::iterator it = _clients.begin(); it != _clients.end();) {
        Client* client = *it;
        std::string request = client->readRequest();

        if (request == "disconnect" || request == "error") {
            delete client;
            it = _clients.erase(it);
        } else if (!request.empty()) {
            std::cout << "Received: " << request << "\n";
            client->sendResponse("HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!");
            it++;
        } else {
            it++;
        }
    }
}

void    Server::run() {
    while (true) {
        acceptClients();
        handleClients();
        usleep(1000); //prevent CPU Overload
    }
}

Server::~Server() {
    for (int i = 0; i < _clients.size(); i++)
        delete _clients[i];
    std::cout << "Server shutting down." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Server& obj) {
    out << "Server Details" << std::endl;
    return out;
}