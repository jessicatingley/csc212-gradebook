#include "Course.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//------------------------------------------------------------------

//------------------------------------------------------------------

Course::Course(std::string category, std::string command, std::vector<std::vector<double>> grades, std::vector<std::vector<std::string>> assignment_names)
    : category(category), command(command), grades(grades), assignment_names(assignment_names) {}

// case 1 (all grades for every category and course overall totals)
// command == TOTAL

// return labs, assignments, projects, exam
std::string Course::TOTAL(std::string category, std::vector<std::vector<double>> grades, std::vector<std::vector<std::string>> assignment_names){
    std::string all_grades = " ";

    for(int i = 0; i <= 3; i++){
        if (i == 0){
            all_grades += "Labs: ";
            for(auto grade : grades[i]){
                all_grades += std::to_string(grade) + " ";
            }
            all_grades += "\n";
        }
        else if(i == 1){
            all_grades += "Assignments: ";
            for(auto grade : grades[i]){
                all_grades += std::to_string(grade) + " ";
            }
            all_grades += "\n";
        }
        else if(i == 2){
            all_grades += "Projects: ";
            for(auto grade : grades[i]){
                all_grades += std::to_string(grade) + " ";
            }
            all_grades += "\n";
        }
        else{
            all_grades += "Exam: ";
            for(auto grade : grades[i]){
                all_grades += std::to_string(grade) + " ";
            }
            all_grades += "\n";
        }
    }
    return all_grades;
}
// case 2 (catagory totals and course overall total)
// command == catagory_total

// return catagory totals
std::string Course::CATEGORY_TOTAL(std::string category, std::vector<std::vector<double>> grades){
    std::string output = "";
    for (int i = 0; i <= 3; i++){
        double total = 0;
        for (const auto grade : grades[i]){
            if (grade != 999){
                total += grade;
            }

            if (i == 0){
                if (grades.size() == 12){
                    std::sort(grades[0].begin(), grades[0].end());
                    // add up first 10 indices (ignore last lowest)
                    for(int a = 2; a <= grades[0].size(); a++){
                        total += grades[0][a];
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
