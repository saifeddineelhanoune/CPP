#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <vector>
#include <map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>
#include <exception>

class Server {
public:
    class ServerException : public std::exception {
    private:
        std::string message;
    public:
        explicit ServerException(const std::string& msg) throw() : message(msg) {}
        virtual ~ServerException() throw() {}
        virtual const char* what() const throw() { return message.c_str(); }
    };

private:
    std::vector<struct pollfd> poll_fds;
    std::map<int, std::string> client_buffers;
    std::string host;
    int server_fd;
    int port;
    static const int MAX_CLIENTS = 1024;
    static const int BUFFER_SIZE = 1024;

    void setNonBlocking(int fd);
    void handleNewConnection();
    void handleClientData(int client_fd);

public:
    Server(const std::string& host, int port);
    ~Server();
    
    void setup();
    void run();
};

#endif