#include "table.h"
#include "parser.h"
#include "student.h"
#include <iostream>
#include <iomanip>
#include <fstream>

Table::~Table()
{
    for(auto student : students)
    {
        delete student;
    }
}

void Table::add(const std::string& first_name, const std::string& last_name, double avg_mark, int attended)
{
    if (first_name.length() > fn_max_len) fn_max_len = first_name.length();
    if (last_name.length() > ln_max_len) ln_max_len = last_name.length();
    students.push_back(new Student(first_name, last_name, avg_mark, attended));
}

void Table::display_header() const 
{
     std::cout << std::setw(10) << "Succeeded " 
              << std::setw(fn_max_len + 1) << std::left << "Name "
              << std::setw(ln_max_len + 1) << std::left << "Surname "
              << std::setw(8) << "Avg mark" << " "
              << std::setw(8) << "Attended" << std::endl;
}

void Table::display() const
{
    display_header();
    for (auto student : students)
    {
        student->display(fn_max_len, ln_max_len);
    }
}