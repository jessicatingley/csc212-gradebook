#include "Individual.h"
#include <iostream>
#include <vector>

Individual::Individual(std::string category, std::string command, std::vector<std::vector<double>> grades, std::vector<std::vector<std::string>> assignment_names)
    : category(category), command(command), grades(grades), assignment_names(assignment_names) {}

/* ------------------------------------------------------------------------------
* Method: DetermineCategory
* Description:
*
* Input: String containing the assignment category the user is looking to find
 *       a grade in.
* Output: Integer representing the row that the category is associated with
* Process: Each row of the 'grades' vector is associated with a category of
 *         assignment. The first row is associated with labs, second row with
 *         assignments, etc. Function simply returns the correct associated
 *         index.
------------------------------------------------------------------------------ */
int Individual::DetermineCategory(std::string category){
    if (category == "LABS") return 0;
    else if (category == "ASSIGNMENTS") return 1;
    else if (category == "PROJECTS") return 2;
    return 3;
}

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
