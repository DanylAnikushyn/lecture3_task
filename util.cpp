#include "util.h"
std::string centered(int width, const std::string& str) {
    int len = str.length();
    if(width < len) { return str; }

    int diff = width - len;
    int pad1 = diff/2;
    int pad2 = diff - pad1;
    return std::string(pad1, ' ') + str + std::string(pad2, ' ');
}

std::vector<std::string> split(std::string str, const std::string& delim) 
{
    size_t pos = 0;
    std::string token;
    std::vector<std::string> row;
    while ((pos = str.find(delim)) != std::string::npos) {
        token = str.substr(0, pos);
        row.push_back(token);
        str.erase(0, pos + delim.length());
    }
    row.push_back(str);

    return row;
}