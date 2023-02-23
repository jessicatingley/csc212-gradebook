#include "Individual.h"
#include "Category.h"
#include "Course.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>

std::vector<std::vector<std::string>> assignment_names = {
        {"Lab1", "Lab2", "Lab3", "Lab4", "Lab5", "Lab6", "Lab7", "Lab8", "Lab9", "Lab10", "Lab11", "Lab12"},
        {"Assignment1", "Assignment2", "Assignment3", "Assignment4"},
        {"ReviewProject", "FinalProject"},
        {"Exam"}};

// Test Individual Class
void TestIndivDetermineCategory(){
    std::string category = "LABS";
    std::string command = "LAB1";
    std::vector<std::vector<double>> grades = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0},
                                            {0, 0},
                                            {0}};
    Individual test_individual(category, command, grades, assignment_names);
    assert(test_individual.DetermineCategory(category) == 0);

    category = "ASSIGNMENTS";
    Individual test_individual1(category, command, grades, assignment_names);
    assert(test_individual1.DetermineCategory(category) == 1);

    category = "PROJECTS";
    Individual test_individual2(category, command, grades, assignment_names);
    assert(test_individual2.DetermineCategory(category) == 2);

    category = "EXAMS";
    Individual test_individual3(category, command, grades, assignment_names);
    assert(test_individual3.DetermineCategory(category) == 3);
};

void TestIndividualGetIndex(){

}

void TestIndividualGrade(){

};

// Test Category Class
void TestCategoryDetermineCategory(){
    std::string category = "LABS";
    std::string command = "LAB1";
    std::vector<std::vector<double>> grades = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0},
                                            {0, 0},
                                            {0}};
    Category test_category(category, command, grades);
    assert(test_category.DetermineCategory(category) == 0);

    category = "ASSIGNMENTS";
    Category test_category1(category, command, grades);
    assert(test_category1.DetermineCategory(category) == 1);

    category = "PROJECTS";
    Category test_category2(category, command, grades);
    assert(test_category2.DetermineCategory(category) == 2);

    category = "EXAMS";
    Category test_category3(category, command, grades);
    assert(test_category3.DetermineCategory(category) == 3);
}
void TestCategoryAllGrades(){
    Category test_category();
};

void TestCategoryTotal(){

};

// Test Course Class
void TestCourseAllGrades(){

};

void TestCourseTotals(){

};

void TestCourseOverall(){

};
