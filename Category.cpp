#include "Category.h"
#include <iostream>

Category::Category(std::string category, std::string command, std::vector<std::vector<int>> grades)
    : category(category), command(command), grades(grades){}

int Category::DetermineCategory(std::string category) {
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

std::string Category::AllGrades(std::string category, std::vector<std::vector<int>> grades) {
    std::string all_grades = " ";
    for(const auto grade : grades[DetermineCategory(category)]){
        all_grades += std::to_string(grade) + " ";
    }
    return all_grades;
}

double Category::Total(std::string category, std::vector<std::vector<int>> grades) {
    double total = 0;
    for(const auto grade : grades[DetermineCategory(category)]){
        total += grade;
    }
    
/*    
// How to take in deliverable name in CLA ?
// Change implementation from pairs to assignment name vector
int Category::GetGrade(std::string category, std::string deliverable, std::vector<std::vector<int>> grades) {
    for(int i = 0; i < grades[DetermineCategory(category)].length(); i++) {
        if(deliverable == grades[DetermineCategory(category)][i].first) {
            return grades[DetermineCategory(category)][i].second;
        }
    }
} 
*/
    
    return total;
}
