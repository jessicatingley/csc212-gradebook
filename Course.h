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
    std::string AllGrades(std::string category, std::vector<std::vector<double>> grades);
    // case 1 (all grades for every category and course overall totals)
    // command == TOTAL
    std::string TOTAL(std::string category, std::vector<std::vector<double>> grades, std::vector<std::vector<std::string>> assignment_names);

    // case 2 (catagory totals and course overall total)
    // command == catagory_total
    std::string CATEGORY_TOTAL(std::string category, std::vector<std::vector<double>> grades);

    // case 3 (only course overall)
    // command == course_total
    double COURSE_TOTAL(std::string category, std::vector<std::vector<double>> grades);
};

#endif
