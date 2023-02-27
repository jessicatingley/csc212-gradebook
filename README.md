# Review Project - CSC 212 Gradebook

## Summary
### Project Description:
We have created a **gradebook** application to interpret course grades into categorical totals and final semester grades. The output will include a course grade calculated based on all possible points that can be earned within the course. The program will evaluate individual deliverables from **CSC 212** and provide an accurate output of grading schemes based on the user request. 

### Project Structure:
The application utilizes 3 classes - `Individual`, `Category`, and `Course` to perform the neccessary functionality.

  The `Individual class` is used to return the name and grade of an individual deliverable from the course.
  
  The `Category class` is used to return all grades from the given category or the category total.
  
  The `Course class` is used to return **any** of the following: 
  - All grades within their respective categories and the course overall
  - ***Only*** category totals and the course overall
  - ***Only*** the course overall

## Planning
### Pseudocode / Flowcharts:

```
Pseudocode - Main.cpp

// Take in file and create 2 dimmensional vector of grades
Open file
Traverse through contents of input file 
	Store line in string
	Extract all numbers from string and push back to new_row
Push new_row into new_file
Return new_file

// Write 2 dimmensional vector of grades to output file
Open file
Traverse outer dimmension of grades
	Traverse inner dimmension of grades
		Write each element in row to out_file (separated by whitespace)
	New line in out_file
Return out_file


// Main Function
// CLA - <input file> <type> <category> <command>

file_name = argv[1]
Create 2 dimmensional vector of grades from input file
Create 2 dimmensional vector of deliverable names
Create vector of deliverable names

// Initialize variables type, category, and command to given CLAs
type = argv[2]
category = argv[3]
command = argv[4]

Convert variable strings to uppercase
Validate type and category using assertions

// Use case for updating grades in file
If var type == "UPDATE"
	new_grade = argv[5] // Initialize grade variable from CLA
	Instantiate new instance of individual class
	grades[][] = new_grade // Update grade value in 2 dimmensional vector of grades
	Write 2 dimmensional vector of grades to output file

// Use case for category class
If var type == "CATEGORY"
	Instantiate new instance of category class
	If var command is "ALLGRADES"
		Print grades
	Else
		Print total

// Use case for individual class
If var type == "INDIVIDUAL"
	Instantiate new instance of individual class
	If deliverble grade == !updated
		Print error message
		Continue
	Print deliverable name
	Print deliverable grade

// Use case for course class
If var type == "COURSE"
	Instantiate new instance of course class
	If var command == "TOTAL"
		Print total
	If var command == "CATEGORY_TOTAL"
		Print category total
	If var command == "COURSE_TOTAL"
		Print course total
  ```
    
    - Add imgs of initial plnning for Individual and Category Class and Input File
    
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
    
The necessary command line arguments for utilizing the `Category class` will be input as follows:
    ```
    <input file name> <class type> <assignment category> <output command>
    ```
The necessary command line arguments for utilizing the `Course class` will be input as follows:
    ```
    <input file name> <class type> <assignment category> <output command>
    ```

## Sample Input/Output
    -Include screenshots with brief explanations of the images used
### Test Cases:
Written tests for the application. Examples of how to run these tests.

#### Credits:
Project created by Brynne Wright, Jessica Tingley, and Alex Sampalis.
Who did what... ? Expln

#### License:
[License]
(link)

