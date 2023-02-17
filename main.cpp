#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "Individual.h"
#include "Category.h"
#include "Course.h"

std::vector<std::vector<int>> FileToVector(std::string file_name){
    //Opens the file for reading
    std::ifstream file(file_name);

    //Creates a string to hold each line in temporarily
    std::string str;

    //Creates a vector to store data in
    std::vector<std::vector<int>> new_file;

    //Iterates over the file, storing one line at a time into 'str'
    while(std::getline(file, str)){
        //Temporary 1D vector of int
        std::vector<int> new_row;

        //Create a stringstream object with our line of integers from the file
        std::istringstream ss(str);

        //Int that will hold our extracted value from the string
        int token;

        //While there are still numbers in this string, extract them
        while(ss >> token){
            //Push numbers into temp vector
            new_row.push_back(token);
        }
        //Push completed row into 2D vector
        new_file.push_back(new_row);
    }
    return new_file;
}

std::ofstream VectorToFile(const std::vector<std::vector<int>>& grade_vec, const std::string& file_name){
    //Open file with write permissions
    std::ofstream out_file(file_name);

    //Use iterator to traverse outer dimension
    for(std::vector<std::vector<int>>::const_iterator row = grade_vec.begin(); row != grade_vec.end(); row++){

        //Iterator to traverse inner dimension
        for(std::vector<int>::const_iterator col = row->begin(); col != row->end(); col++){
            //Output each element to the file with a space at the end
            out_file << *col << " ";
        }

        //Output a newline symbol to the file
        out_file << "\n";
    }
    return out_file;
}

int main(int argc, char* argv[]){
    std::vector<std::vector<int>> grades = FileToVector(argv[1]);

    //Type = class the user is looking to use
    std::string type = argv[2];

    //Category = category the user wants grades from (labs, assignments, etc)
    std::string category = argv[3];

    //Command = which method of the specified class the user is looking to use
    std::string command = argv[4];

    //Make each variable completely uppercase
    std::transform(type.begin(), type.end(), type.begin(), ::toupper);
    std::transform(category.begin(), category.end(), category.begin(), ::toupper);
    std::transform(command.begin(), command.end(), command.begin(), ::toupper);

    //Use case for category class
    if(type == "CATEGORY"){
        Category use_category(category, command, grades);
        if(command == "ALLGRADES"){
            std::cout << use_category.AllGrades(category, grades) << std::endl;
        }
        std::cout<< use_category.Total(category, grades) << std::endl;
    }
    return 0;
}
