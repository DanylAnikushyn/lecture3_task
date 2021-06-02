#include "table.h"
#include "util.h"
#include <iostream>
#include <iomanip>
#include <fstream>

void Table::add(const std::string& first_name, const std::string& last_name, double avg_mark, int attended)
{
    first_names.push_back(first_name);
    if (first_name.length() > fn_max_len) fn_max_len = first_name.length();
    last_names.push_back(last_name);
    if (last_name.length() > ln_max_len) ln_max_len = last_name.length();
    avg_marks.push_back(avg_mark);
    attended_vec.push_back(attended);
    if (avg_mark > 4.0 && attended > 5) 
        succeeded_vec.push_back(true);
    else 
        succeeded_vec.push_back(false);
}

void Table::display() const
{
    std::cout << std::setw(10) << "Succeeded " 
              << std::setw(fn_max_len + 1) << std::left << "Name "
              << std::setw(ln_max_len + 1) << std::left << "Surname "
              << std::setw(8) << "Avg mark" << " "
              << std::setw(8) << "Attended" << std::endl;
    for (int i = 0; i < first_names.size(); ++i)
        std::cout << std::setw(10) << centered(10, succeeded_vec[i] ? "+" : "")
                  << std::setw(fn_max_len) << std::left << first_names[i] << " "
                  << std::setw(ln_max_len) << std::left << last_names[i] << " "
                  << std::setw(8) << std::right << std::setprecision(3) << avg_marks[i] << " " 
                  << std::setw(8) << centered(8, std::to_string(attended_vec[i]))
                  << std::endl;
}

bool file_to_table(const char* filename, Table& table)
{
    if (!filename) 
    {
        std::cerr << "Please specify filename" << std::endl;
        return false;
    }
    std::ifstream in(filename);

    if (!in)
    {
        std::cerr << "Cannot open the file: " << filename << std::endl;
        return false;
    }

    std::string str;
    while (std::getline(in, str))
    {
        std::vector<std::string> str_vec = split(str, ",");
        if (str_vec.size() == 4) 
        {
            table.add(str_vec[0], str_vec[1], std::stod(str_vec[2]), std::stoi(str_vec[3]));
        }
        else
        {
            std::cerr << "Wrong formating" << std::endl;
            return false;
        }
            
    }
    in.close();
    return true;
}