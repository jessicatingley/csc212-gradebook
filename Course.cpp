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
    std::string all_grades = "";

    for(int i = 0; i <= 3; i++){
        if (i == 0){
            all_grades += "Labs: ";
            for(auto grade : grades[i]){
                if(grade == 999) all_grades += "Grade Not Entered ";
                else all_grades += std::to_string(grade) + " ";
            }
            all_grades += "\n";
        }
        else if(i == 1){
            all_grades += "Assignments: ";
            for(auto grade : grades[i]){
                if(grade == 999) all_grades += "Grade Not Entered ";
                else all_grades += std::to_string(grade) + " ";
            }
            all_grades += "\n";
        }
        else if(i == 2){
            all_grades += "Projects: ";
            for(auto grade : grades[i]){
                if(grade == 999) all_grades += "Grade Not Entered ";
                else all_grades += std::to_string(grade) + " ";
            }
            all_grades += "\n";
        }
        else{
            all_grades += "Exam: ";
            for(auto grade : grades[i]){
                if(grade == 999) all_grades += "Grade Not Entered ";
                else all_grades += std::to_string(grade) + " ";
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
            if (i == 0){
                if (grades.size() == 12){
                    std::sort(grades[0].begin(), grades[0].end());
                    // add up first 10 indices (ignore last lowest)
                    for(int a = 2; a <= grades[0].size(); a++){
                        total += grades[0][a];
                    }
                    output += "Lab total: " + std::to_string(total);
                }
                else{
                    for (const auto grade : grades[i]) {
                        if (grade != 999) total += grade;
                    }
                    output += "Lab total: " + std::to_string(total);
                    output += "\n";
                }
            }
            if (i == 1){
                total = 0;
                for (const auto grade : grades[i]) {
                    if (grade != 999) total += grade;
                }
                output += "Assignment total: " + std::to_string(total);
                output += "\n";
            }
            if (i == 2){
                total = 0;
                for (const auto grade : grades[i]) {
                    if (grade != 999) total += grade;
                }
                output += "Project total: " + std::to_string(total);
                output += "\n";
            }
            if (i == 3)
            {
                total = 0;
                for (const auto grade : grades[i]) {
                    if (grade != 999) total += grade;
                }
                output += "Project total: " + std::to_string(total);
                output += "\n";
            }
        }
    return output;
}

// case 3 (only course overall)
// command == course_total
// return course total
double Course::COURSE_TOTAL(std::string category, std::vector<std::vector<double>> grades){
    double total = 0;

    // rows
    for (const auto category : grades){
        // columns
        for (const auto grade : category){
            if (total != 999) total += grade;
        }
    }
    return total;
}
