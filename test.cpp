#include "Individual.h"
#include "Category.h"
#include "Course.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>

std::vector<std::vector<std::string>> assignment_names = {
        {"Lab 1", "Lab 2", "Lab 3", "Lab 4", "Lab 5", "Lab 6", "Lab 7", "Lab 8", "Lab 9", "Lab 10", "Lab 11", "Lab 12"},
        {"Assignment 1", "Assignment 2", "Assignment 3", "Assignment 4"},
        {"Review Project", "Final Project"},
        {"Final Exam"}};

// Test Individual Class
void TestIndivDetermineCategory(){
    std::string category = "LABS";
    std::string command = "LAB1";
    std::vector<std::vector<int>> grades = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
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

void TestIndividualGrade(){

};

// Test Category Class
void TestCategoryDetermineCategory(){
    std::string category = "LABS";
    std::string command = "LAB1";
    std::vector<std::vector<int>> grades = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
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
