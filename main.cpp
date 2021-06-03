#include "table.h"
#include "parser.h"
#include <iostream>

int main(int argc, char* argv[])
{
    Parser* parser = Parser::getParser();
    Table table;
    if (!argv[1]) 
    {
        std::cerr << "Please specify filename" << std::endl;
        return 1;
    }
    if (parser->parse_from_file(argv[1], table))
    {
        table.display();
    }
    parser->destroy();
    return 0;
}