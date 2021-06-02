#include "table.h"
#include "util.h"

int main(int argc, char* argv[])
{
    Table table;
    if (file_to_table(argv[1], table))
    {
        table.display();
    }
    return 0;
}