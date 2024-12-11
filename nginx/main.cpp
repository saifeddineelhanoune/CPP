#include "server/Server.hpp"
#include "server/ServerException.hpp"
#include <iostream>

int main() {
    try {
        Server server("127.0.0.1", 8080);
        std::cout << "Starting server on 127.0.0.1:8080..." << std::endl;
        server.setup();
        server.run();
    } catch (const ServerException& e) {
        std::cerr << "Server error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}