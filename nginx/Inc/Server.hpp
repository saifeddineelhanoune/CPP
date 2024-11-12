#pragma once

#include "Response.hpp"
#include "Request.hpp"
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fstream>
#include <sstream>

using namespace std;

class Server {
    private:
        int serverFd;
        struct sockaddr_in address;
        const int port;
        const string   rootDirectory; // the directory of the static website to get
        string  readFile(const string &filename);
        Response handleReq(const Request& req);
    public:
        Server(int port, const string &root);
        ~Server();
};
