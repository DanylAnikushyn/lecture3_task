#include "parser.h"
#include <iostream>
#include <fstream>
#include <sstream>

Parser* Parser::instance = nullptr;

std::string centered(int width, const std::string& str) {
    int len = str.length();
    if(width < len) { return str; }

    int diff = width - len;
    int pad1 = diff/2;
    int pad2 = diff - pad1;
    return std::string(pad1, ' ') + str + std::string(pad2, ' ');
}

Parser::Parser() {}

Parser* Parser::getParser()
{
    if(!instance) 
    {
        instance = new Parser();
    }
    return instance;
}

void Parser::destroy()
{
    delete instance;
    instance = nullptr;
}

bool Parser::parse(std::istream& stream, Table& table)
{
    std::string row;
    std::vector<std::string> fields_vec;
    while (std::getline(stream, row))
    {
        std::stringstream str_stream(row);
        std::string field;
        while (std::getline(str_stream, field, ',')) 
        {
            fields_vec.push_back(field);
        }
        if (fields_vec.size() != 4)
        {
            std::cerr << "Wrong formating" << std::endl;
            return false;
        }
        table.add(fields_vec[0], fields_vec[1], std::stod(fields_vec[2]), std::stoi(fields_vec[3]));   
        fields_vec.clear();
    }
    return true;
}

bool Parser::parse_from_file(const std::string& filename, Table& table)
{
    std::ifstream in(filename);

    if (!in)
    {
        std::cerr << "Cannot open the file: " << filename << std::endl;
        return false;
    }

    bool returned = parse(in, table);
    in.close();
    return returned;
}