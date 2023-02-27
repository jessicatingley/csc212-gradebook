#include <iostream>
#include <vector>

#ifndef CSC212_GRADEBOOK_COURSE_H
#define CSC212_GRADEBOOK_COURSE_H

class Course
{
private:
    std::string category;
    std::string command;
    std::vector<std::vector<double>> grades;
    std::vector<std::vector<std::string>> assignment_names;

public:
    Course(std::string category, std::string command, std::vector<std::vector<double>> grades, std::vector<std::vector<std::string>> assignment_names);
    std::string TOTAL(std::vector<std::vector<double>> grades);
    std::string CATEGORY_TOTAL(std::vector<std::vector<double>> grades);
    double COURSE_TOTAL(std::vector<std::vector<double>> grades);
};

#endif
