#include "../Inc/Reactor.hpp"

Reactor::Reactor(int port) {
    sockaddr_in serverAddr;
    socketFd = socket(2, 1, 0);
    if (socketFd < 0)
        throw std::runtime_error("Socket failed");
    std::memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = 2;
    serverAddr.sin_addr.s_addr = (u_int32_t)0x00000000;
    serverAddr.sin_port = htons(port);

    if (bind(socketFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
        throw std::runtime_error("Bind Failed");
    if (listen(socketFd, 128) < 0)
        throw std::runtime_error("Listen error");
    fcntl(socketFd, 4, 0x0004);
    handlers[socketFd] = new AcceptorHandler(socketFd, handlers);
}

void    Reactor::run() {
    while (true) {
        fd_set fds;
        int maxFd = socketFd;
        int selectFd = 0;

        FD_ZERO(&fds);
        for (std::map<int, EventHandler*>::iterator it = handlers.begin();\
        it != handlers.end();\
        it++) {
            FD_SET(it->first, &fds);
            if (it->first > maxFd)
                maxFd = it->first;
        }
        selectFd = select(maxFd + 1, &fds, NULL, NULL, NULL);
        if (selectFd < 0)
            throw std::runtime_error("Select failed");
    }
}
