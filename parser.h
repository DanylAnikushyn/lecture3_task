#ifndef UTIL_H
#define UTIL_H
#include "table.h"
#include <string>
#include <vector>
#include <istream>
// centering string to output
class Parser 
{
public:
    static Parser* getParser();
    static void destroy();
    bool parse_from_file(const std::string& filename, Table& table);
private:
    Parser();
    bool parse(std::istream& stream, Table& table);
    static Parser* instance;
};
std::string centered(int width, const std::string& str);
#endif