#ifndef STUDENT_H
#define STUDENT_H
#include <string>
class Student 
{
public:
    Student();
    Student(std::string first_name, std::string last_name, double avg_mark, int attended);
    void display(int fn_max_len, int ln_max_len) const;
private:
    std::string first_name;
    std::string last_name;
    double avg_mark;
    int attended;
    bool succeeded;
};
#endif