#include <iostream>
#include <vector>

#ifndef CSC212_GRADEBOOK_CATEGORY_H
#define CSC212_GRADEBOOK_CATEGORY_H
class Category{
private:
    std::string category;
    std::string command;
    std::vector<std::vector<int>> grades;
    int DetermineCategory(std::string category);
public:
    friend void TestCategoryDetermineCategory();
    Category(std::string category, std::string command, std::vector<std::vector<int>> grades);
    std::string AllGrades(std::string category, std::vector<std::vector<int>> grades);
    double Total(std::string category, std::vector<std::vector<int>> grades);
};
#endif //CSC212_GRADEBOOK_CATEGORY_H
