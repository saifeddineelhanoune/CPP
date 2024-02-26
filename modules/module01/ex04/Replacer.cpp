#include "FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : filename(filename), s1(s1), s2(s2) {

    }

std::string FileReplacer::ReplaceFile(const std::string& source, const std::string& s1, const std::string& s2) {
    std::string result;
    size_t pos =  0;
    size_t findPos;
    while ((findPos = source.find(s1, pos)) != std::string::npos) {
        result.append(source, pos, findPos - pos);
        result += s2;
        pos = findPos + s1.length();
    }
    result += source.substr(pos);
    return result;
}

