#include "student.h"
#include "parser.h"
#include <iostream>
#include <string>
#include <iomanip>

Student::Student(const std::string& first_name, const std::string& last_name, double avg_mark, int attended) :
    m_first_name(first_name), m_last_name(last_name), m_avg_mark(avg_mark), m_attended(attended)
{
    (m_avg_mark > 4.0 && m_attended > 5) ? m_succeeded = true : m_succeeded = false;
}

void Student::display(int fn_max_len, int ln_max_len) const
{
    std::cout << std::setw(10) << centered(10, m_succeeded ? "+" : "")
                  << std::setw(fn_max_len) << std::left << m_first_name << " "
                  << std::setw(ln_max_len) << std::left << m_last_name << " "
                  << std::setw(8) << std::right << std::setprecision(3) << m_avg_mark << " " 
                  << std::setw(8) << centered(8, std::to_string(m_attended))
                  << std::endl;
}