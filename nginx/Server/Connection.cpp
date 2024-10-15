#include "Connection.hpp"

Connection::Connection() : _sockFd(-1) {

}

void    Connection::setNonBlocking() {
    int flags = fcntl(_sockFd, 3, 0);
    if (flags != -1)
        fcntl(_sockFd, 4, flags | O_NONBLOCK);
}

void    Connection::closeConnection() {
    if (_sockFd != -1) {
        close(_sockFd);
        _sockFd = -1;
    }
}

Connection::~Connection() {
    closeConnection();
}