#include "table.h"
#include "parser.h"
#include "student.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <memory>

void Table::add(const std::string& first_name, const std::string& last_name, double avg_mark, int attended)
{
    if (first_name.length() > m_fn_max_len) m_fn_max_len = first_name.length();
    if (last_name.length() > m_ln_max_len) m_ln_max_len = last_name.length();
    m_students.push_back(std::make_unique<Student>(first_name, last_name, avg_mark, attended));
}

void Table::display_header() const 
{
     std::cout << std::setw(10) << "Succeeded " 
              << std::setw(m_fn_max_len + 1) << std::left << "Name "
              << std::setw(m_ln_max_len + 1) << std::left << "Surname "
              << std::setw(8) << "Avg mark" << " "
              << std::setw(8) << "Attended" << std::endl;
}

void Table::display() const
{
    display_header();
    for (const auto& student : m_students)
    {
        student->display(m_fn_max_len, m_ln_max_len);
    }
}