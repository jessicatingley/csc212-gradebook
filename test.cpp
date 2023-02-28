#include "Individual.h"
#include "Category.h"
#include "Course.h"
#include <iostream>
#include <vector>
#include <cassert>

std::vector<std::vector<std::string>> assignment_names = {
        {"LAB1", "LAB2", "LAB3", "LAB4", "LAB5", "LAB6", "LAB7", "LAB8", "LAB9", "LAB10", "LAB11", "LAB12"},
        {"ASSIGNMENT1", "ASSIGNMENT2", "ASSIGNMENT3", "ASSIGNMENT4"},
        {"REVIEWPROJECT", "FINALPROJECT"},
        {"EXAM"}};

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
    std::string category = "LABS";
    std::string command = "LAB1";
    std::vector<std::vector<double>> grades = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 0, 0},
                                               {0, 0},
                                               {0}};

    Individual test_individual(category, command, grades, assignment_names);
    assert(test_individual.GetIndex(category, command, assignment_names) == 0);

    command = "EXAM";
    Individual test_individual1(category, command, grades, assignment_names);
    assert(test_individual1.GetIndex(category, command, assignment_names) == 0);

    command = "LAB8";
    Individual test_individual2(category, command, grades, assignment_names);
    assert(test_individual2.GetIndex(category, command, assignment_names) == 7);

    command = "ASSIGNMENT4";
    Individual test_individual3(category, command, grades, assignment_names);
    assert(test_individual3.GetIndex(category, command, assignment_names) == 3);

    command = "REVIEWPROJECT";
    Individual test_individual4(category, command, grades, assignment_names);
    assert(test_individual4.GetIndex(category, command, assignment_names) == 0);
}

void TestIndividualGrade(){
    std::string category = "LABS";
    std::string command = "LAB1";
    std::vector<std::vector<double>> grades = {{20.3, 80.88, 90.3, 30, 100, 999, 10, 10.0, 40, 30, 100, 30},
                                               {100, 90.1, 30, 10},
                                               {20, 30},
                                               {999}};
    Individual test_individual(category, command, grades, assignment_names);
    assert(test_individual.GetGrade(category, command, grades) == 20.3);

    command = "LAB12";
    Individual test_individual1(category, command, grades, assignment_names);
    assert(test_individual1.GetGrade(category, command, grades) == 30);

    category = "ASSIGNMENTS";
    command = "ASSIGNMENT1";
    Individual test_individual2(category, command, grades, assignment_names);
    assert(test_individual2.GetGrade(category, command, grades) == 100);

    command = "ASSIGNMENT4";
    Individual test_individual3(category, command, grades, assignment_names);
    assert(test_individual3.GetGrade(category, command, grades) == 10);

    category = "PROJECTS";
    command = "REVIEWPROJECT";
    Individual test_individual4(category, command, grades, assignment_names);
    assert(test_individual4.GetGrade(category, command, grades) == 20);

    command = "FINALPROJECT";
    Individual test_individual5(category, command, grades, assignment_names);
    assert(test_individual5.GetGrade(category, command, grades) == 30);

    category = "EXAMS";
    command = "EXAM";
    Individual test_individual6(category, command, grades, assignment_names);
    assert(test_individual6.GetGrade(category, command, grades) == 999);
};

// Test Category Class
void TestCategoryDetermineCategory(){
    std::string category = "LABS";
    std::string command = "LAB1";
    std::vector<std::vector<double>> grades = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0},
                                            {0, 0},
                                            {0}};
    Category test_category(category, grades);
    assert(test_category.DetermineCategory(category) == 0);

    category = "ASSIGNMENTS";
    Category test_category1(category, grades);
    assert(test_category1.DetermineCategory(category) == 1);

    category = "PROJECTS";
    Category test_category2(category, grades);
    assert(test_category2.DetermineCategory(category) == 2);

    category = "EXAMS";
    Category test_category3(category, grades);
    assert(test_category3.DetermineCategory(category) == 3);
}
void TestCategoryAllGrades(){
    std::string category = "LABS";
    std::vector<std::vector<double>> grades = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 999, 0},
                                               {999, 0},
                                               {0}};
    Category test_category(category, grades);
    assert(test_category.AllGrades(category, grades) == "0 0 0 0 0 0 0 0 0 0 0 0 ");

    category = "ASSIGNMENTS";
    Category test_category1(category, grades);
    assert(test_category1.AllGrades(category, grades) == "0 0 Grade Not Entered 0 ");

    category = "PROJECTS";
    Category test_category2(category, grades);
    assert(test_category2.AllGrades(category, grades) == "Grade Not Entered 0 ");

    category = "EXAMS";
    Category test_category3(category, grades);
    assert(test_category3.AllGrades(category, grades) == "0 ");
};

void TestCategoryTotal(){
    std::string category = "LABS";
    std::vector<std::vector<double>> grades = {{80.5, 999, 90, 70, 0, 98, 0, 11.2, 999, 0, 9, 0},
                                               {8.8, 70, 999, 0},
                                               {999, 2},
                                               {999}};
    Category test_category(category, grades);
    assert(test_category.Total(category, grades) == 358.7);

    category = "ASSIGNMENTS";
    Category test_category1(category, grades);
    assert(test_category1.Total(category, grades) == 78.8);

    category = "PROJECTS";
    Category test_category2(category, grades);
    assert(test_category2.Total(category, grades) == 2);

    category = "EXAMS";
    Category test_category3(category, grades);
    assert(test_category3.Total(category, grades) == 0);
};

// Test Course Class
void TestTotal(){
    std::string category = "LABS";
    std::string command = "LAB1";
    std::vector<std::vector<double>> grades = {{70, 999, 100, 90, 90.6, 80.8, 100, 50.5, 999, 20.3, 77.7, 999},
                                               {55.5, 30.6, 999, 100},
                                               {90.9, 30.6},
                                               {100}};
    Course test_course(category, command, grades, assignment_names);
    assert(test_course.TOTAL(grades) == "Labs: 70 Grade Not Entered 100 90 90.6 80.8 100 50.5 Grade Not Entered 20.3 77.7 Grade Not Entered\n"
                                        "Assignments: 55.5 30.6 Grade Not Entered 100\n"
                                        "Projects: 90.9 30.6\n"
                                        "Exam: 100");


};
