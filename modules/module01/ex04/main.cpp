#include "FileReplacer.hpp"

int main(int argc, char* argv[]) {
    if (argc !=  4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return  1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    FileReplacer replacer(filename, s1, s2);
    replacer.ReplaceFile(filename, s1, s2);
    return  0;
}
