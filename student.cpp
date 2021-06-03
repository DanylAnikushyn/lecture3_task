#include "student.h"
#include "parser.h"
#include <iostream>
#include <string>
#include <iomanip>

Student::Student(std::string first_name, std::string last_name, double avg_mark, int attended) :
    first_name(first_name), last_name(last_name), avg_mark(avg_mark), attended(attended)
{
    (avg_mark > 4.0 && attended > 5) ? succeeded = true : succeeded = false;
}

void Student::display(int fn_max_len, int ln_max_len) const
{
    std::cout << std::setw(10) << centered(10, succeeded ? "+" : "")
                  << std::setw(fn_max_len) << std::left << first_name << " "
                  << std::setw(ln_max_len) << std::left << last_name << " "
                  << std::setw(8) << std::right << std::setprecision(3) << avg_mark << " " 
                  << std::setw(8) << centered(8, std::to_string(attended))
                  << std::endl;
}