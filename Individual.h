

#ifndef CSC212_GRADEBOOK_INDIVIDUAL_H
#define CSC212_GRADEBOOK_INDIVIDUAL_H

#include <iostream>
#include <vector>

class Individual
{
private:
    std::string category;
    std::string command; // Deliverable
    std::vector<std::vector<int>> grades; 
    std::vector<std::vector<std::string>> assignment_names; // Vector of deliverable names
    int DetermineCategory(std::string category); // Implimentation from category class
    // Find index of given deliverable
    int GetIndex(std::string category, std::string command, std::vector<std::vector<std::string>> assignment_names);

public:
    friend void TestIndivDetermineCategory();
    Individual(std::string category, std::string command, std::vector<std::vector<int>> grades, std::vector<std::vector<std::string>> assignment_names);
    // Return grade at deliverable index
    int GetGrade(std::string category, std::string command, std::vector<std::vector<int>> grades);
};

#endif // CSC212_GRADEBOOK_INDIVIDUAL_H
