#ifndef STUDENT_H
#define STUDENT_H
#include <string>
class Student 
{
public:
    Student();
    Student(const std::string& first_name, const std::string& last_name, double avg_mark, int attended);
    void display(int fn_max_len, int ln_max_len) const;
private:
    std::string m_first_name;
    std::string m_last_name;
    double m_avg_mark;
    int m_attended;
    bool m_succeeded;
};
#endif