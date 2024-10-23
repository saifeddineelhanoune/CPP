#include "../Inc/AcceptorHandler.hpp"
#include "../Inc/CLientHandler.hpp"

AcceptorHandler::AcceptorHandler(int fd, std::map<int, EventHandler*> &handlersMap) : \
listenFd(fd), handlers(handlersMap) {

}

void    AcceptorHandler::handleEvent(int) {
    int clientFd = accept(listenFd, NULL, NULL);
    if (clientFd < 0)
        throw std::runtime_error("Accept failed");
    std::cout << "New connection accepted" << clientFd <<  std::endl;
    fcntl(clientFd, F_SETFL, O_NONBLOCK);
    handlers[clientFd] = new ClientHandler(clientFd, handlers);
}