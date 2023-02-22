#include "Individual.h"
#include <iostream>

Individual::Individual(std::string category, std::string deliverable, std::vector<std::vector<int>> grades)
        : category(category), deliverable(deliverable), grades(grades){}

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

int Individual::GetGrade(std::string category, std::string deliverable, std::vector<std::vector<int>> grades) {

    for(int i = 0; i < grades[DetermineCategory(category)].length(); i++) {
        if(deliverable == grades[DetermineCategory(category)][i].first) {
            return grades[DetermineCategory(category)][i].second;
        }
    }

}
