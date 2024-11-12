#include "../Inc/Server.hpp"

Server::Server(int port, const string &root) : port(port),
 rootDirectory(root) {
    serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd < 0) 
        throw std::runtime_error("socket failed");
    int opt = 1;
}