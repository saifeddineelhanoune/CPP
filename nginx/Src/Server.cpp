#include "../Inc/Server.hpp"

Server::Server(int port, const string &root) : port(port),
 rootDirectory(root) {
    serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd < 0) 
        throw runtime_error("socket failed");
    int opt = 1;
    if (setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)));
        throw runtime_error("setsockopt failed");
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(serverFd, (struct sockaddr *)&address, sizeof(address)) < 0)
        throw runtime_error("bind failed");
}

string  Server::readFile(const string &filename) {
    ifstream file((rootDirectory + filename).c_str());
    stringstream ss;
    if (!file.is_open()) {
        return "";
    }
    ss << file.rdbuf();
    return ss.str();
}

Response Server::handleReq(const Request& req) {
    Response response;
    string   path, content;

    if (req.getMethod() != "GET") {
        response.setStatus(405, "Method Not Allowed");
        response.setBody("Only GET method is supported");
        return response;
    }
    path = req.getPath();
    if (path == "/") path = "/index.html";
    content = readFile(path);
    if (content.empty()) {
        response.setStatus(404, "Not Found");
        response.setBody(content);
    }
    return response;
}

void    Server::start() {
    if (listen(serverFd, 3) < 0)
        throw runtime_error("listen Failed");
    cout << "Server listening on port" << port << endl;
}

