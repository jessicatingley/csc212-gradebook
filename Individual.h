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

public:
    friend void TestIndivDetermineCategory();
    friend void TestIndividualGetIndex();
    Individual(std::string category, std::string command, std::vector<std::vector<double>> grades, std::vector<std::vector<std::string>> assignment_names);
    // Return grade at deliverable index
    int DetermineCategory(std::string category); // Implementation from category class
    // Find index of given deliverable
    int GetIndex(std::string category, std::string command, std::vector<std::vector<std::string>> assignment_names);
    double GetGrade(std::string category, std::string command, std::vector<std::vector<double>> grades);
};

#endif // CSC212_GRADEBOOK_INDIVIDUAL_H
