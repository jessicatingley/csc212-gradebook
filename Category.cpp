#include <iostream>
#include <vector>
#include "Category.h"

Category::Category(std::string category, std::vector<std::vector<double>> grades)
    : category(category), grades(grades){}


/* ------------------------------------------------------------------------------
* Method: DetermineCategory
* Description:
*
* Input: Category the user is looking to find a grade in (string)
* Output: Row of the 2D grades vector that is associated with given category (int)
* Process: Each row of the 'grades' vector is associated with a category of
*          assignment. The first row is associated with labs, second row with
*          assignments, etc. Function simply returns the correct associated
*          index.
------------------------------------------------------------------------------ */
int Category::DetermineCategory(std::string category) {
    if(category == "LABS") return 0;
    else if(category == "ASSIGNMENTS") return 1;
    else if(category == "PROJECTS") return 2;
    return 3;
}



/* ------------------------------------------------------------------------------
* Method: AllGrades
* Description:
*
* Input: - Category the user is looking to find a grade in (string)
 *       - All grades sorted by category and in chronological order (2D vector)
* Output: All grades in the indicated category (string)
* Process: Row of grades vector associated with the given category is iterated
 *         over and each grade is added to a string.
------------------------------------------------------------------------------ */
std::string Category::AllGrades(std::string category, std::vector<std::vector<double>> grades) {
    std::string all_grades = " ";
    for(const auto grade : grades[DetermineCategory(category)]){
        if(grade == 999) all_grades += "Grade Not Entered ";
        else all_grades += std::to_string(grade) + " ";
    }
    return all_grades;
}



/* ------------------------------------------------------------------------------
* Method: Total
* Description:
*
* Input: - Category the user is looking to find a grade in (string)
 *       - All grades sorted by category and in chronological order (2D vector)
* Output: Total of all grades in the indicated category (double)
* Process: Row of grades vector associated with the given category is iterated
 *         over and each grade is added to a total.
------------------------------------------------------------------------------ */
double Category::Total(std::string category, std::vector<std::vector<double>> grades) {
    double total = 0;
    for(const auto grade : grades[DetermineCategory(category)]){
        if(grade != 999) total += grade;
    }
    return total;
}
