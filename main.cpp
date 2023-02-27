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
 * Input: Name of the given file to be read from (string)
 * Output: Grades read in from the file (2D vector)
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

/* ------------------------------------------------------------------------------
 * Function: VectorToFile
 * Description:
 *
 * Input: - Grades from each category in chronological order (2D vector)
 *        - Name of given file to be written to (string)
 * Output: Output file stream
 * Process: Each vector within the 2D vector is iterated over. Each item in the
 *          inner vectors is output to the file with a space following it. At
 *          the end of the inner vector, a newline is inserted and the next inner
 *          vector is iterated over.
 ------------------------------------------------------------------------------ */
std::ofstream VectorToFile(const std::vector<std::vector<double>>& grade_vec, const std::string& file_name){
    std::ofstream out_file(file_name);

    //Iterate over outer dimension
    for(std::vector<std::vector<double>>::const_iterator row = grade_vec.begin(); row != grade_vec.end(); row++){

        //Iterator over inner dimension
        for(std::vector<double>::const_iterator col = row->begin(); col != row->end(); col++){
            out_file << *col << " ";
        }
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
 * Command = which method of the specified class the user is looking to use;
 *           for Individual class, command stores the assignment which the
 *           user wants to view
 ------------------------------------------------------------------------------ */

int main(int argc, char* argv[]){
    if(argc != 5 && argc != 6){
        std::cout << "You have entered an invalid type.\n";
        std::cout << "Usage: ./prog <file_name> <type> <category> <command>\n";
        std::cout << "Usage to update a grade: ./prog <file_name> <UPDATE> <category> <command> <grade>\n";
        std::cout << "\t<category>\tCategory of grade you would like to change\n";
        std::cout << "\t<command>\tName of the assignment you would like to update, to be written with no whitespace\n";
        std::cout << "Valid types: INDIVIDUAL, CATEGORY, COURSE, UPDATE";
        std::cout << "Valid categories: LABS, ASSIGNMENTS, PROJECTS, EXAMS";
        return 0;
    }
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
    if(std::find(valid_types.begin(), valid_types.end(), type) == valid_types.end()){
        std::cout << "You have entered an invalid type.\n";
        std::cout << "Usage: ./prog <file_name> <type> <category> <command>\n";
        std::cout << "Usage to update a grade: ./prog <file_name> <UPDATE> <category> <command> <grade>\n";
        std::cout << "\t<category>\tCategory of grade you would like to change\n";
        std::cout << "\t<command>\tName of the assignment you would like to update, to be written with no whitespace\n";
        std::cout << "Valid types: INDIVIDUAL, CATEGORY, COURSE, UPDATE";
        return 0;
    }

    std::vector<std::string> valid_categories = {"LABS", "ASSIGNMENTS", "PROJECTS", "EXAMS"};
    if(std::find(valid_categories.begin(), valid_categories.end(), category) == valid_categories.end()){
        std::cout << "You have entered an invalid category.\n";
        std::cout << "Usage: ./prog <file_name> <type> <category> <command>\n";
        std::cout << "Usage to update a grade: ./prog <file_name> <UPDATE> <category> <command> <grade>\n";
        std::cout << "\t<category>\tCategory of grade you would like to change\n";
        std::cout << "\t<command>\tName of the assignment you would like to update, to be written with no whitespace\n";
        std::cout << "Valid categories: LABS, ASSIGNMENTS, PROJECTS, EXAMS";
        return 0;
    }

    if(type == "UPDATE"){
        if(argc != 6){
            std::cout << "Usage: ./prog <file_name> <UPDATE> <category> <command> <grade>\n";
            std::cout << "\t<file_name>\tFile you would like read from and written to\n";
            std::cout << "\t<UPDATE>\tTo update a grade, enter UPDATE exactly\n";
            std::cout << "\t<category>\tCategory of grade you would like to change\n";
            std::cout << "\t<command>\tName of the assignment you would like to update, to be written with no whitespace\n";
            std::cout << "\t<grade>\tThe new value of the grade\n";
            return 0;
        }
        int new_grade = std::stoi(argv[5]);
        Individual update_grade(category, command, grades, assignment_names);
        grades[update_grade.DetermineCategory(category)][update_grade.GetIndex(category, command, assignment_names)] = new_grade;
        VectorToFile(grades, argv[1]);
    }

    //Use case for category class
    if(type == "CATEGORY"){
        Category use_category(category, grades);
        if(command == "ALLGRADES"){
            std::cout << "Your grades for " << category << " are " << use_category.AllGrades(category, grades) << std::endl;
        }
        else std::cout<< "Your category total for " << category << " is " << use_category.Total(category, grades) << std::endl;
    }
    
    //Use case for individual class
    if(type == "INDIVIDUAL") {
        Individual use_individual(category, command, grades, assignment_names);
        if(use_individual.GetGrade(category, command, grades) == 999){
            std::cout << "This grade has not been entered yet" << std::endl;
            return 0;
        }
        std::cout << "Deliverable Name: " << command << std::endl;
        std::cout << command << "Grade: " << use_individual.GetGrade(category, command, grades) << std::endl;
    }
 
 // use case for course class
    if (type == "COURSE"){
        Course use_course(category, command, grades, assignment_names);
        if (command == "TOTAL") std::cout << use_course.TOTAL(grades) << std::endl;
        if (command == "CATEGORYTOTAL") std::cout << use_course.CATEGORY_TOTAL(grades) << std::endl;
        if (command == "COURSETOTAL") std::cout << "Course total: " << use_course.COURSE_TOTAL(grades) << " out of 1000 possible points" << std::endl;
    }
    return 0;
}
