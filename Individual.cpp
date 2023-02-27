#include "Individual.h"
#include <iostream>
#include <vector>

Individual::Individual(std::string category, std::string command, std::vector<std::vector<double>> grades, std::vector<std::vector<std::string>> assignment_names)
    : category(category), command(command), grades(grades), assignment_names(assignment_names) {}

/* ------------------------------------------------------------------------------
* Method: DetermineCategory
* Description:
*
* Input: Category the user is looking to find a grade in (string)
* Output: Row of the 2D grades vector that is associated with given category (int)
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



/* ------------------------------------------------------------------------------
* Method: GetIndex
* Description:
*
* Input: - Category the user is looking to find a grade in (string)
 *       - Assignment name that the user wants the grade of (string)
 *       - All assignment names sorted by category and in chronological
 *         order (2D vector)
* Output: Column of the 2D grades vector that is associated with the given
 *        assignment (int)
* Process: The indices of an assignment and its corresponding grade align in
 *         both the 2D vector of assignment names and the 2D vector of grades.
 *         The row associated with category will contain the grade the user is
 *         looking for. In the 2D vector of assignment names, comparing each
 *         element in the row with the assignment name the user wants a grade for
 *         will result in the column of the grade.
------------------------------------------------------------------------------ */
int Individual::GetIndex(std::string category, std::string command, std::vector<std::vector<std::string>> assignment_names){
    for (int i = 0; i < grades[DetermineCategory(category)].size(); i++){
        if (command == assignment_names[DetermineCategory(category)][i]){
            return i;
        }
    }
}



/* ------------------------------------------------------------------------------
* Method: GetGrade
* Description:
*
* Input: - Category the user is looking to find a grade in (string)
 *       - Assignment name that the user wants the grade of (string)
 *       - All grades sorted by category and in chronological order (2D vector)
* Output: Grade of assignment the user has indicated (double)
* Process: Utilizing the previous two functions to determine the correct row
 *         and column where the grade is located, the grade is returned from
 *         the grades vector.
------------------------------------------------------------------------------ */
double Individual::GetGrade(std::string category, std::string command, std::vector<std::vector<double>> grades){
    return grades[DetermineCategory(category)][GetIndex(category, command, assignment_names)];
}
