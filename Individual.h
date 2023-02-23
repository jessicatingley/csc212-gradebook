

#ifndef CSC212_GRADEBOOK_INDIVIDUAL_H
#define CSC212_GRADEBOOK_INDIVIDUAL_H

#include <iostream>
#include <vector>

class Individual
{
private:
    std::string category;
    std::string command; // Deliverable
    std::vector<std::vector<double>> grades;
    std::vector<std::vector<std::string>> assignment_names; // Vector of deliverable names
    int DetermineCategory(std::string category); // Implimentation from category class
    // Find index of given deliverable
    int GetIndex(std::string category, std::string command, std::vector<std::vector<std::string>> assignment_names);

public:
    friend void TestIndivDetermineCategory();
    Individual(std::string category, std::string command, std::vector<std::vector<double>> grades, std::vector<std::vector<std::string>> assignment_names);
    // Return grade at deliverable index
    double GetGrade(std::string category, std::string command, std::vector<std::vector<double>> grades);
};

#endif // CSC212_GRADEBOOK_INDIVIDUAL_H
