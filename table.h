#ifndef TABLE_H
#define TABLE_H
#include "student.h"
#include <string>
#include <vector>
#include <memory>
class Table 
{
public:
    void add(const std::string& first_name, const std::string& last_name, double avg_mark, int attended);
    void display() const;
private:
    std::vector<std::unique_ptr<Student>> m_students;

    int m_fn_max_len = 5;
    int m_ln_max_len = 8;

    void display_header() const;
};
#endif