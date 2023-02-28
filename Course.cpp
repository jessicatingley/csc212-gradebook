#include "Course.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

Course::Course(std::string category, std::string command, std::vector<std::vector<double>> grades, std::vector<std::vector<std::string>> assignment_names)
    : category(category), command(command), grades(grades), assignment_names(assignment_names) {}


/* ------------------------------------------------------------------------------
 * Method: Total
 * Description:
 *
 * Input: All grades sorted by category and in chronological order (2D vector)
 * Output: All grades for each category (string)
 * Process: Each grade in each row of the grades vector is pushed to a string.
 *          Rows are labeled with their associated category.
 ------------------------------------------------------------------------------ */
std::string Course::TOTAL(std::vector<std::vector<double>> grades){
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



/* ------------------------------------------------------------------------------
 * Method: CategoryTotal
 * Description:
 *
 * Input: All grades sorted by category and in chronological order (2D vector)
 * Output: Total of all grades in each category (string)
 * Process: Each grade in each row of the grades vector is added to a total.
 *          Rows are labeled with their associated category and the associated
 *          total is displayed with this label.
 ------------------------------------------------------------------------------ */
std::string Course::CATEGORYTOTAL(std::vector<std::vector<double>> grades){
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

/* ------------------------------------------------------------------------------
 * Method: CourseTotal
 * Description:
 *
 * Input: All grades sorted by category and in chronological order (2D vector)
 * Output: Total number of points for the course (double)
 * Process: Each vector within the 2D vector is iterated over. Each grade in the
 *          inner vector is added to a running total for the course.
 ------------------------------------------------------------------------------ */
double Course::COURSETOTAL(std::vector<std::vector<double>> grades){
    double total = 0;
    for (const auto category : grades){
        for (const auto grade : category){
            if (total != 999) total += grade;
        }
    }
    return total;
}
