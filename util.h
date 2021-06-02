#ifndef UTIL_H
#define UTIL_H
#include <string>
#include <vector>
// centering string to output
std::string centered(int width, const std::string& str);
std::vector<std::string> split(std::string str, const std::string& delim);
#endif