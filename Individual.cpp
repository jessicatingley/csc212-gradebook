#include "Individual.h"
#include <iostream>

Individual::Individual(std::string category, std::string command, std::vector<std::vector<double>> grades, std::vector<std::vector<std::string>> assignment_names)
    : category(category), command(command), grades(grades), assignment_names(assignment_names) {}

int Individual::DetermineCategory(std::string category){
    if (category == "LABS")
        return 0;
    if (category == "ASSIGNMENTS")
        return 1;
    if (category == "PROJECTS")
        return 2;
    if (category == "EXAMS")
        return 3;
}

// Get index of individual deliverable (command) from assignment_names
int Individual::GetIndex(std::string category, std::string command, std::vector<std::vector<std::string>> assignment_names){
    for (int i = 0; i < grades[DetermineCategory(category)].size(); i++){
        if (command == assignment_names[DetermineCategory(category)][i]){
            return i;
        }
    }
}

// Get grade of individual deliverable (command) from grades
double Individual::GetGrade(std::string category, std::string command, std::vector<std::vector<double>> grades){
    return grades[DetermineCategory(category)][GetIndex(category, command, assignment_names)];
}
