#ifndef TABLE_H
#define TABLE_H
#include <string>
#include <vector>
class Table 
{
public:
    void add(const std::string& first_name, const std::string& last_name, double avg_mark, int attended);
    void display() const;
private:
    std::vector<std::string> first_names;
    std::vector<std::string> last_names;
    std::vector<double> avg_marks;
    std::vector<int> attended_vec;
    std::vector<bool> succeeded_vec;

    int fn_max_len = 5;
    int ln_max_len = 8;
};

bool file_to_table(const char* filename, Table& table);
#endif