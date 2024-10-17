#include "Server/Client.hpp"
#include "Server/Server.hpp"
#include "Server/Connection.hpp"

int main() {
    try {
        // Initialize the server on port 8080
        Server server(8080);
        std::cout << "Server started on port 8080..." << std::endl;

        // Vector to store connected clients
        std::vector<Client*> clients;

        while (true) {
            // Check for new connections
            try {
                Client* newClient = server.acceptClients();
                if (newClient != nullptr) {
                    std::cout << "New client connected!" << std::endl;
                    clients.push_back(newClient);
                }
            } catch (const std::exception& e) {
                std::cerr << "Error accepting new connection: " << e.what() << std::endl;
            }

            // Handle requests from connected clients
            try {
                server.handleClients(clients);
            } catch (const std::exception& e) {
                std::cerr << "Error handling client: " << e.what() << std::endl;
            }

            // We can include a sleep here if we want to slow down the loop, but for simplicity, it runs continuously
        }

    } catch (const std::exception& e) {
        std::cerr << "Server error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}