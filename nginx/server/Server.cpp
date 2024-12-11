#include "Server.hpp"
#include <iostream>
#include <cstring>
#include <cerrno>

Server::Server(const std::string& host, int port) : host(host), port(port) {}

Server::~Server() {
    for (size_t i = 0; i < poll_fds.size(); i++)
        close(poll_fds[i].fd);
}

void    Server::setNonBlocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1)
        throw ServerException("Failed to get socket flags");
    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1)
        throw ServerException("Failed to set socket non-blocking");
}

void    Server::setup() {
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
        throw ServerException("Failed to create socket");
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
        throw ServerException("failed to reuse socket");
    setNonBlocking(server_fd);
    struct  sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == -1)
        throw ServerException("Failed to bind socket");
    if (listen(server_fd, SOMAXCONN) == -1)
        throw ServerException("Failed to listen from socket");
    struct pollfd server_pollfd;
    server_pollfd.fd = server_fd;
    server_pollfd.events = POLLIN;
    poll_fds.push_back(server_pollfd);
}

void    Server::handleNewConnection() {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    if (client_fd == -1) {
        if (errno != EWOULDBLOCK && errno != EAGAIN)
            std::cerr << "Failed to accept connection" << std::endl;
        return ;
    }
    setNonBlocking(client_fd);
    struct pollfd client_pollfd;
    client_pollfd.fd = client_fd;
    client_pollfd.events = POLLIN;
    poll_fds.push_back(client_pollfd);
}

void    Server::handleClientData(int client_fd) {
    char    buffer[BUFFER_SIZE];
    ssize_t bytes_read = recv(client_fd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_read <= 0) { //Closed connection or error
        close(client_fd);
        for (size_t i = 0; i < poll_fds.size(); i++) {
            if (poll_fds[i].fd == client_fd) {
                poll_fds.erase(poll_fds.begin() + i);
                break;
            }
        }
        client_buffers.erase(client_fd);
        return;
    }
    buffer[bytes_read] = '\0';
    client_buffers[client_fd].append(buffer);

    //we'll later add HTTP request parsing and response handling
    // for now, just echo the data back
   std::cout << "Received data: " << buffer << std::endl;
    
    // Send HTTP response
    std::string response = "HTTP/1.1 200 OK\r\n"
                          "Content-Type: text/plain\r\n"
                          "Content-Length: 11\r\n"
                          "\r\n"
                          "Hello World\n";
    
    send(client_fd, response.c_str(), response.length(), 0);
    
    // Close connection after sending response
    close(client_fd);
    for (size_t i = 0; i < poll_fds.size(); ++i) {
        if (poll_fds[i].fd == client_fd) {
            poll_fds.erase(poll_fds.begin() + i);
            break;
        }
    }
}

void    Server::run() {
    while(true) {
        int poll_count = poll(&poll_fds[0], poll_fds.size(), -1);
        if (poll_count == -1) {
            if (errno == EINTR) continue;
            throw   ServerException("Poll Failed");
        }
        for (size_t i = 0; i < poll_fds.size(); i++) {
            if (poll_fds[i].revents & POLLIN) {
                if (poll_fds[i].fd == server_fd)
                    handleNewConnection();
                else
                    handleClientData(poll_fds[i].fd);
            }
        }
    }
}