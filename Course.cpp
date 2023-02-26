#include "Course.h"
#include <iostream>
#include <string>
#include <vector>

//------------------------------------------------------------------

//------------------------------------------------------------------

Course::Course(std::string category, std::string command, std::vector<std::vector<int>> grades)
    : category(category), command(command), grades(grades), assignment_names(assignment_names) {}

// case 1 (all grades for every category and course overall totals)
// command == TOTAL

// return labs, assignments, projects, exam
std::string Course::TOTAL(std::string category, std::vector<std::vector<double>> grades)
{
    for (int i = 0; i++; i <= 3)
    {
        std::string all_grades = " ";
        for (const auto grade : grades[i])
        {
            all_grades += std::to_string(grade) + " ";
        }
        return all_grades;
        all_grades.clear();
    }
}
// case 2 (catagory totals and course overall total)
// command == catagory_total

// return catagory totals
double Course::CATEGORY_TOTAl(std::string category, std::vector<std::vector<double>> grades)
{
    for (int i = 0; i++; i < 3)
    {
        double total = 0;
        for (const auto grade : grades[i])
        {
            total += grade;
        }
        if (i = 0)
        {
            std::cout << "Lab total: " << total << std::endl;
        }
        if (i = 1)
        {
            std::cout << "Assignment total: " << total << std::endl;
        }
        if (i = 2)
        {
            std::cout << "Project total: " << total << std::endl;
        }
        if (i = 3)
        {
            std::cout << "Exam total: " << total << std::endl;
        }
    }
}

// case 3 (only course overall)
// command == course_total
// return course total
double Course::COURSE_TOTAL(std::string category, std::vector<std::vector<double>> grades)
{
    double total = 0;
    int i = 0;
    for (const auto grade : grades[i])
    {
        total += grade;
        i++;
    }
    return total;
}
