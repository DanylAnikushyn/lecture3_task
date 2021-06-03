#ifndef TABLE_H
#define TABLE_H
#include "student.h"
#include <string>
#include <vector>
class Table 
{
public:
    ~Table();
    void add(const std::string& first_name, const std::string& last_name, double avg_mark, int attended);
    void display() const;
private:
    std::vector<Student*> students;

    int fn_max_len = 5;
    int ln_max_len = 8;

    void display_header() const;
};
#endif