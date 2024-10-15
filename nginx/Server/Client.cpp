#include "Client.hpp"

Client::Client() {

}

Client::Client(int clientSocket, struct sockaddr_in addr) {
    _sockFd= clientSocket;
    _clientAddr = addr;
    setNonBlocking(); // Make the client non-blocking
}

Client::Client(const Client& obj) {
    _clientAddr = obj._clientAddr;
    _sockFd = obj._sockFd;
}

Client& Client::operator=(const Client& obj) {
    if (this != &obj) {
        _clientAddr = obj._clientAddr;
        _sockFd = obj._sockFd;  
    }
    return *this;
}

std::string Client::readRequest() {
    char buffer[1024];
    int bytesRead = recv(_sockFd, buffer, sizeof(buffer) - 1, 0);
    
    if (bytesRead > 0) {
        buffer[bytesRead] = '\0'; // Null-terminate the buffer
        return std::string(buffer);
    } else if (bytesRead == 0) {
        // Connection closed
        return "disconnect";
    } else if (errno != EWOULDBLOCK && errno != EAGAIN) {
        // Some error occurred
        return "error";
    }
    return ""; // No data available
}

void    Client::sendResponse(const std::string& response) {
    send(_sockFd, response.c_str(), response.size(), 0);
}

Client::~Client() {
    std::cout << "Client disconnected" << std::endl;
}