#include <iostream>
#include <vector>
#include "Category.h"

Category::Category(std::string category, std::string command, std::vector<std::vector<double>> grades)
    : category(category), command(command), grades(grades){}

int Category::DetermineCategory(std::string category) {
    if(category == "LABS") return 0;
    else if(category == "ASSIGNMENTS") return 1;
    else if(category == "PROJECTS") return 2;
    return 3;
}

std::string Category::AllGrades(std::string category, std::vector<std::vector<double>> grades) {
    std::string all_grades = " ";
    for(const auto grade : grades[DetermineCategory(category)]){
        all_grades += std::to_string(grade) + " ";
    }
    return all_grades;
}

double Category::Total(std::string category, std::vector<std::vector<double>> grades) {
    double total = 0;
    for(const auto grade : grades[DetermineCategory(category)]){
        total += grade;
    }
    return total;
}
