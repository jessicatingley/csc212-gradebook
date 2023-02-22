
#ifndef CSC212_GRADEBOOK_INDIVIDUAL_H
#define CSC212_GRADEBOOK_INDIVIDUAL_H

#include <iostream>
#include <vector>

class Individual {
private:
    std::string category;
    std::string deliverable;
    std::vector<std::vector<int>> grades;
    int DetermineCategory(std::string category);

public:
    Individual(std::string category, std::string deliverable, std::vector<std::vector<int>> grades);
    int GetGrade(std::string category, std::string deliverable, std::vector<std::vector<int>> grades);
};

#endif //CSC212_GRADEBOOK_INDIVIDUAL_H
