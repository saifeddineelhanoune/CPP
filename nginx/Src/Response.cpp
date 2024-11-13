#include "../Inc/Response.hpp"

Response::Response(int code, const string &message) : \
statusCode(code), statusMessage(message) {
    headers["Server"] = "webserv/1.0";
    headers["Connection"] = "close";
}

void    Response::setStatus(int code, const string &message) {
    statusCode = code;
    statusMessage = message;
}

void    Response::setHeader(const string &key, const string &value) {
    headers[key] = value;
}

void    Response::setBody(const string &content) {
    body += content;
    headers["Content-Length"] = to_string(content.length());
}

string  Response::toString() const {
    string res = "Webserv/1.0" + to_string(statusCode) + " " + statusMessage + "\r\n";
    for (std::map<std::string, std::string>::const_iterator it = headers.begin(); 
        it != headers.end(); ++it) {
        res += it->first + ": " + it->second + "\r\n";
    }
    res += "\r\n" + body;
    return res;
}

// string  Response::getDateTime() {
//     char buffer[128];
//     time_t now = time(0);
//     struct tm* gmt = gmtime(&now);
//     strftime(buffer, sizeof(buffer), "%a, %d %b %Y %H::%M:%S GMT", gmt);
//     return string(buffer);
// }

// Response::Response() : statusCode(0), statusMsg("Default") {
//     headers["Date"] = getDateTime();
//     headers["connection"] = "keep-alive";
// }

// map<string, string> Response::getHeaders() const {
//     return headers;
// }

// int Response::getStatusCode() const {
//     return statusCode;
// }

// string  Response::getStatusMsg() const {
//     return statusMsg;
// }

// string  Response::generateStatusLine() const {
//     ostringstream oss;
//     oss << "HTTP/1.1" << statusCode << " " << statusMsg << "\r\n";
//     return oss.str();
// }

// void    Response::addHeader(const string &key, const string &value) {
//     headers[key] = value;
// }

// void    Response::setBody(const string &content) {
//     body = content;
//     addHeader("Content-length", to_string(body.size()));
// }

// // const Response::statusEntry Response::statusTable[] = {
// //     {100, "Continue"}, {101, "Switching Protocols"},
// //     {200, "OK"}, {201, "Created"}, {202, "Accepted"}, {203, "Non-Authoritative Information"},
// //     {204, "No Content"}, {205, "Reset Content"}, {206, "Partial Content"},
// //     {300, "Multiple Choices"}, {301, "Moved Permanently"}, {302, "Found"},
// //     {303, "See Other"}, {304, "Not Modified"}, {307, "Temporary Redirect"},
// //     {400, "Bad Request"}, {401, "Unauthorized"}, {402, "Payment Required"},
// //     {403, "Forbidden"}, {404, "Not Found"}, {405, "Method Not Allowed"},
// //     {406, "Not Acceptable"}, {407, "Proxy Authentication Required"},
// //     {408, "Request Timeout"}, {409, "Conflict"}, {410, "Gone"},
// //     {411, "Length Required"}, {412, "Precondition Failed"},
// //     {413, "Payload Too Large"}, {414, "URI Too Long"}, {415, "Unsupported Media Type"},
// //     {416, "Range Not Satisfiable"}, {417, "Expectation Failed"},
// //     {500, "Internal Server Error"}, {501, "Not Implemented"},
// //     {502, "Bad Gateway"}, {503, "Service Unavailable"}, {504, "Gateway Timeout"},
// //     {505, "HTTP Version Not Supported"}
// // };

// void    Response::setErrorPage(int errorCode) {
//     const statusEntry* entry = nullptr;
//     string  filename = to_string(errorCode) + ".html";
//     string  line, content;
//     ifstream    file(filename.c_str());

//     for (unsigned int i = 0; i < sizeof(statusTable) \
//     / sizeof(statusTable[0]); i++) {
//         if (statusTable[i].code == errorCode) {
//             entry = &statusTable[i];
//             break;
//         }
//     }
//     if (entry == nullptr) return;
//     if (file.is_open()) {
//         while(getline(file, line))
//             content += line;
//         file.close();
//     } else cerr << "Unable to open file" << filename << endl;
//     setBody(content);
// }

// void    Response::clearHeaders() {
//     //back to default
//     headers.clear();
//     headers["Date"] = getDateTime();
//     headers["Connection"] = "keep-alive";
// }

// void    Response::generateHeaders() const {
//     headers["Date"] = getDateTime();
//     headers["Server"] = "42_webserv | NGINX-like";

//     headers["Cache-Control"] = "no-cache";
//     headers["Expires"] = "-1";
//     headers["ETag"] = "W/\"default-etag\"";  // Example ETag
//     headers["Last-Modified"] = getCurrentDateTime();
// }

