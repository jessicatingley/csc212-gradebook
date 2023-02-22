

#ifndef CSC212_GRADEBOOK_INDIVIDUAL_H
#define CSC212_GRADEBOOK_INDIVIDUAL_H

#include <iostream>
#include <vector>

class Individual
{
private:
    std::string category;
    std::string command;
    std::vector<std::vector<int>> grades;
    std::vector<std::vector<std::string>> assignment_names;
    int DetermineCategory(std::string category);
    int GetIndex(std::string category, std::string command, std::vector<std::vector<std::string>> assignment_names);

public:
    Individual(std::string category, std::string command, std::vector<std::vector<int>> grades, std::vector<std::vector<std::string>> assignment_names);
    int GetGrade(std::string category, std::string command, std::vector<std::vector<int>> grades);
};

#endif // CSC212_GRADEBOOK_INDIVIDUAL_H
