#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cassert>
#include "Individual.h"
#include "Category.h"
#include "Course.h"


/* ------------------------------------------------------------------------------
 * Function: FileToVector
 * Description:
 *
 * Input: Name of the file to be read as a string
 * Output: 2D vector of doubles
 * Process: File is iterated over line by line and each item in the line is
 *          tokenized and pushed to a temporary vector. At the end of this line,
 *          the temporary vector is pushed to the vector being returned.
 ------------------------------------------------------------------------------ */
std::vector<std::vector<double>> FileToVector(std::string file_name){
    std::ifstream file(file_name);
    std::string str;
    std::vector<std::vector<double>> new_file;

    //Iterates over the file, storing one line at a time into 'str'
    while(std::getline(file, str)){
        std::vector<double> new_row;
        std::istringstream ss(str);
        double token;

        //While there are still numbers in this string, extract them
        while(ss >> token){
            new_row.push_back(token);
        }
        new_file.push_back(new_row);
    }
    return new_file;
}

std::ofstream VectorToFile(const std::vector<std::vector<double>>& grade_vec, const std::string& file_name){
    //Open file with write permissions
    std::ofstream out_file(file_name);

    //Use iterator to traverse outer dimension
    for(std::vector<std::vector<double>>::const_iterator row = grade_vec.begin(); row != grade_vec.end(); row++){

        //Iterator to traverse inner dimension
        for(std::vector<double>::const_iterator col = row->begin(); col != row->end(); col++){
            //Output each element to the file with a space at the end
            out_file << *col << " ";
        }

        //Output a newline symbol to the file
        out_file << "\n";
    }
    return out_file;
}


/* ------------------------------------------------------------------------------
 * Function: main
 * Important Points:
 *
 * Type = class the user is looking to use
 * Category = category the user wants grades from (labs, assignments, etc)
 * Command = which method of the specified class the user is looking to use
 ------------------------------------------------------------------------------ */

int main(int argc, char* argv[]){
    std::vector<std::vector<double>> grades = FileToVector(argv[1]);
    std::vector<std::vector<std::string>> assignment_names = {
            {"LAB1", "LAB2", "LAB3", "LAB4", "LAB5", "LAB6", "LAB7", "LAB8", "LAB9", "LAB10", "LAB11", "LAB12"},
            {"ASSIGNMENT1", "ASSIGNMENT2", "ASSIGNMENT3", "ASSIGNMENT4"},
            {"REVIEWPROJECT", "FINALPROJECT"},
            {"EXAM"}};
    std::vector<std::string> assignment_names_flat = {"LAB1", "LAB2", "LAB3", "LAB4", "LAB5", "LAB6", "LAB7", "LAB8",
                                                      "LAB9", "LAB10", "LAB11", "LAB12", "ASSIGNMENT1", "ASSIGNMENT2",
                                                      "ASSIGNMENT3", "ASSIGNMENT4", "REVIEWPROJECT", "FINALPROJECT",
                                                      "EXAM"};

    std::string type = argv[2];
    std::string category = argv[3];
    std::string command = argv[4];

    std::transform(type.begin(), type.end(), type.begin(), ::toupper);
    std::transform(category.begin(), category.end(), category.begin(), ::toupper);
    std::transform(command.begin(), command.end(), command.begin(), ::toupper);

    std::vector<std::string> valid_types = {"INDIVIDUAL", "CATEGORY", "COURSE", "UPDATE"};
    assert(std::find(valid_types.begin(), valid_types.end(), type) != valid_types.end());

    std::vector<std::string> valid_categories = {"LABS", "ASSIGNMENTS", "PROJECTS", "EXAMS"};
    assert(std::find(valid_categories.begin(), valid_categories.end(), category) != valid_categories.end());

    if(type == "UPDATE"){
        int new_grade = std::stoi(argv[5]);
        Individual update_grade(category, command, grades, assignment_names);
        grades[update_grade.DetermineCategory(category)][update_grade.GetIndex(category, command, assignment_names)] = new_grade;
        VectorToFile(grades, argv[1]);
    }

    //Use case for category class
    if(type == "CATEGORY"){
        Category use_category(category, command, grades);
        if(command == "ALLGRADES"){
            std::cout << use_category.AllGrades(category, grades) << std::endl;
        }
        std::cout<< use_category.Total(category, grades) << std::endl;
    }
    
    //Use case for individual class
    if(type == "INDIVIDUAL") {
        assert(std::find(assignment_names_flat.begin(), assignment_names_flat.end(), command) != assignment_names_flat.end());
        Individual use_individual(category, command, grades, assignment_names);
        if(use_individual.GetGrade(category, command, grades) == 999){
            std::cout << "This grade has not been entered yet" << std::endl;
            return 0;
        }
        std::cout << "Deliverable Name: " << command << std::endl;
        std::cout << command << "Grade: " << use_individual.GetGrade(category, command, grades) << std::endl;
    }
    
    return 0;
}
