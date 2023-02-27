#include "Course.h"
#include <iostream>
#include <string>
#include <vector>

//------------------------------------------------------------------

//------------------------------------------------------------------

Course::Course(std::string category, std::string command, std::vector<std::vector<double>> grades, std::vector<std::vector<std::string>> assignment_names)
    : category(category), command(command), grades(grades), assignment_names(assignment_names) {}

// case 1 (all grades for every category and course overall totals)
// command == TOTAL

// return labs, assignments, projects, exam
std::string Course::TOTAL(std::string category, std::vector<std::vector<double>> grades, std::vector<std::vector<std::string>> assignment_names)
{
    for (int i = 0; i++; i <= 3)
    {
        std::string all_grades = " ";
        for (const auto grade : grades[i])
        {
            all_grades += std::to_string(grade) + " ";
        }
        return all_grades;
        if (i == 0)
        {
            // have to drop two of the lowest grades
            std::cout << "Labs: " << all_grades << std::endl;
        }
        if (i == 1)
        {
            std::cout << "Assignments: " << all_grades << std::endl;
        }
        if (i == 2)
        {
            std::cout << "Projects: " << all_grades << std::endl;
        }
        if (i == 3)
        {
            std::cout << "Exam: " << all_grades << std::endl;
        }
        all_grades.clear();
    }
}
// case 2 (catagory totals and course overall total)
// command == catagory_total

// return catagory totals
std::string Course::CATEGORY_TOTAL(std::string category, std::vector<std::vector<double>> grades)
{
    for (int i = 0; i++; i < 3)
    {
        double total = 0;
        for (const auto grade : grades[i])
        {
            if (grade != 999)
            {
                total += grade;
            }

            if (i == 0)
            {
                // grade[0]
                if (grades.size() == 12)
                {
                    total = 0;
                    //  drop 2 lowest grades
                    // sort in descending
                    std::sort(grades.begin(), grades.end(), std::greater<int>());
                    // add up first 10 indicies (ignore last lowest)
                    for (int a = 0; a++; a < 10)
                    {
                        total += grades[a];
                    }
                }

                else
                {
                    std::cout << "Lab total: " << total << std::endl;
                }
            }
            if (i == 1)
            {
                std::cout << "Assignment total: " << total << std::endl;
            }
            if (i == 2)
            {
                std::cout << "Project total: " << total << std::endl;
            }
            if (i == 3)
            {
                std::cout << "Exam total: " << total << std::endl;
            }
        }
    }
}

// case 3 (only course overall)
// command == course_total
// return course total
double Course::COURSE_TOTAL(std::string category, std::vector<std::vector<double>> grades)
{
    double total = 0;

    // rows
    for (const auto category : grades)
    {
        // columns
        for (const auto grade : category)
        {
            if (total != 999)
            {
                total += grade;
            }
        }
    }
    return total;
}
