#include "../Inc/ClientHandler.hpp"

ClientHandler::ClientHandler(int fd, std::map<int, EventHandler*> &handlers) : \
clientFd(fd), handlers(handlers) {

}

void    ClientHandler::handleEvent(int) {
    char    buffer[BUFFER_SIZE];

    int offset = read(clientFd, buffer, sizeof(buffer) - 1);
    if (offset <= 0){
        closeConnection();
        throw std::runtime_error("Read failed");
    }
    buffer[offset] = '\0';
    std::cout << "Received request: " << buffer << std::endl;
    send(clientFd, HTML_RESPONSE.c_str(), HTML_RESPONSE.size(), 0);
    closeConnection();
}

void    ClientHandler::closeConnection() {
    close(clientFd);
    handlers.erase(clientFd);
    delete this;
}