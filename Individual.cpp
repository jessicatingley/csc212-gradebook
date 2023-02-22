#include "Individual.h"
#include <iostream>

Individual::Individual(std::string category, std::string deliverable, std::vector<std::vector<int>> grades, std::vector<std::vector<std::string>> assignment_names)
        : category(category), deliverable(deliverable), grades(grades), assignment_names(assignment_names){}

int Individual::DetermineCategory(std::string category) {
//    enum category_type{
//        LABS,
//        ASSIGNMENTS,
//        PROJECTS,
//        EXAM
//    };

    if(category == "LABS") return 0;
    if(category == "ASSIGNMENTS") return 1;
    if(category == "PROJECTS") return 2;
    if(category == "EXAM") return 3;

}

// Get index of individual deliverable from assignment_names
int Individual::GetIndex(std::string category, std::string deliverable, std::vector<std::vector<std::string>> assignment_names) {
    for(int i = 0; i < grades[DetermineCategory(category)].length(); i++) {
        if(deliverable == assignment_names[DetermineCategory(category)][i]) {
            return i;
        }
    }
}

// Get grade of individual deliverable from grades
int Individual::GetGrade(std::string category, std::string deliverable, std::vector<std::vector<std::string>> grades) {
     return grades[DetermineCategory(category)][GetIndex(category, deliverable, assignment_names)]
}
