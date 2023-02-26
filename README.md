# Review Project - CSC 212 Gradebook

## Summary
### Project Description:
What problem does the program solve?
We have created a gradebook application to interpret course grades into categorical totals and final semester grades. The output will include a course grade calculated based on all possible points that can be earned within the course. The program will evaluate individual deliverables from CSC 212 and provide an accurate output of grading schemes based on the user request. 

### Project Structure:
How does the program work?
The application utilizes 3 classes - Individual, Category, and Course to perform the neccessary functionality.

The Individual class is used to return the name and grade of an individual deliverable from the course.
  
The Category class is used to return all grades from the given category or the category total.
  
The Course class is used to return any of the following: 
  - All grades within their respective categories and the course overall
  - Only category totals and the course overall
  - Only the course overall

## Planning
### Pseudocode / Flowcharts:
    - Code planning evidence here
    
## Compilation Instructions
    - Can include screenshots to show examples of the program running (SS of how to compile, SS of example input file)
    
## Runtime Instruction
The first command line argument should ***always*** be the text file.  
The necessary command line arguments for utilizing the **Individual class** will be input as follows:  
    ```
    $ ./prog file_name.txt INDIVIDUAL CATEGORY_OF_ASSIGNMENT ASSIGNMENT_NAME  
    ```  
    Valid input for `CATEGORY_OF_ASSIGNMENT`:    
    - `LABS`   
    - `ASSIGNMENTS`     
    - `PROJECTS`     
    - `EXAMS`      
    Examples of valid input for `ASSIGNMENT_NAME`:     
    - `LAB1`   
    - `ASSIGNMENT3`    
    - `REVIEWPROJECT`    
    - `FINALPROJECT`   
    - `EXAM`   
    Important notes:     
    - `CATGORY_OF_ASSIGNMENT` ***must*** correspond with `ASSIGNMENT_NAME`   
      - I.e. entering `LABS` for `CATEGORY_OF_ASSIGNMENT` and `ASSIGNMENT3` for `ASSIGNMENT_NAME` would result in an incorrect grade being returned.    
    - No spaces should be left in input for `ASSIGNMENT_NAME`    
    - If input is invalid, the program will break with an assert.   
The necessary command line arguments for utilizing the Category class will be input as follows:
    <input file name> <class type> <assignment category> <output command>
The necessary command line arguments for utilizing the Course class will be input as follows:
    <input file name> <class type> <assignment category> <output command>

## Sample Input/Output
    -Include screenshots with brief explanations of the images used
### Test Cases:
Written tests for the application. Examples of how to run these tests.

#### Credits:
Project created by Brynne Wright, Jessica Tingley, and Alex Sampalis.

#### License:
[License]
(link)

