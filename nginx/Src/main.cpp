#include "../Inc/Server.hpp"

int main() {
    try {
        Server serv(8080, "../www/");
        server.start();
    }
}