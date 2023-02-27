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
  
## Compilation Instructions
**The necessary command line arguments provided during compile time are ordered as follows:** <br />
./prog `<file name>` `<type>` `<category>` `<command>` <br />
<br /> A multi-word CLA ***must*** be written in concatination and all individual CLAs ***must*** be separated by whitespace.
```
Example -
./prog my_grades.txt individual projects finalproject
```
<!-- Include screenshots to show examples of the program running (SS of how to compile, SS of example input file) -->

### Input File Formatting:
```
Data - file_name.txt

999 999 999 999 999 999 999 999 999 999 999 999
999 999 999 999
999 999
999
```

```
Structure - file_name.txt

LAB1 LAB2 LAB3 LAB4 LAB5 LAB6 LAB7 LAB8 LAB9 LAB10 LAB11 LAB12
ASSIGNMENT1 ASSIGNMENT2 ASSIGNMENT3 ASSIGNMENT4
REVIEWPROJECT FINALPROJECT
EXAM
```

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
    
<!-- Add imgs of initial plnning for Individual and Category Class and Input File -->
    
## Runtime Instruction
The first command line argument should ***always*** be the input file[^1]. <br />  
**The necessary command line arguments for utilizing the `Individual` class will be input as follows:**  
$ ./prog `file_name.txt`[^1] `INDIVIDUAL`[^2] `CATEGORY_OF_ASSIGNMENT`[^3] `ASSIGNMENT_NAME`[^4]    
    <br /> Valid input for `CATEGORY_OF_ASSIGNMENT`:    
    - 'LABS'   
    - 'ASSIGNMENTS'     
    - 'PROJECTS'     
    - 'EXAMS'      
    Examples of valid input for `ASSIGNMENT_NAME`:     
    - 'LAB1'   
    - 'ASSIGNMENT3'    
    - 'REVIEWPROJECT'    
    - 'FINALPROJECT'   
    - 'EXAM'   
    Important notes:     
    - `CATGORY_OF_ASSIGNMENT` ***must*** correspond with `ASSIGNMENT_NAME`   
      - I.e. entering 'LABS' for `CATEGORY_OF_ASSIGNMENT` and 'ASSIGNMENT3' for `ASSIGNMENT_NAME` would result in an incorrect grade being returned.    
    - No spaces should be left in input for `ASSIGNMENT_NAME`
    	- I.e. entering 'ASSIGNMENT 3' for `ASSIGNMENT_NAME` would be invalid.
    - If input is invalid, the program will break with an assert.
    
**The necessary command line arguments for utilizing the `Category` class will be input as follows:**  
$ ./prog `file_name.txt`[^1] `CATEGORY`[^2] `CATEGORY_OF_ASSIGNMENT`[^3] `COMMAND`[^4]    
    <br /> Valid input for `CATEGORY_OF_ASSIGNMENT`:    
    - 'LABS'   
    - 'ASSIGNMENTS'     
    - 'PROJECTS'     
    - 'EXAMS'      
    Examples of valid input for `COMMAND`:     
    - 'ALLGRADES'   
    - 'TOTAL'     
    Important notes:     
    - A valid `COMMAND` ***must*** be given when type 'CATEGORY' is used.       
    - No spaces should be left in input for `COMMAND`
    	- I.e. entering 'ALL GRADES' for `COMMAND` would be invalid.
    - If input is invalid, the program will break with an assert.
    
**The necessary command line arguments for utilizing the `Course` class will be input as follows:**  
$ ./prog `file_name.txt`[^1] `COURSE`[^2] `CATEGORY_OF_ASSIGNMENT`[^3] `COMMAND`[^4]    
    <br /> Valid input for `CATEGORY_OF_ASSIGNMENT`:    
    - 'LABS'   
    - 'ASSIGNMENTS'     
    - 'PROJECTS'     
    - 'EXAMS'      
    Examples of valid input for `COMMAND`:     
    - 'TOTAL'   
    - 'CATEGORY_TOTAL'   
    - 'COURSE_TOTAL'     
    Important notes:     
    - A valid `COMMAND` ***must*** be given when type 'COURSE' is used.       
    - No spaces should be left in input for `COMMAND`
    	- I.e. entering 'COURSE TOTAL' for `COMMAND` would be invalid.
    - If input is invalid, the program will break with an assert.

[^1]: The input file (in this case 'file_name.txt') is your own dataset of grades passed in by the first CLA.
  This is the file our gradebook program will be evaluating or updating. 
  
[^2]: This string represents the 'type' variable which identifies the class you will be utilizing to evaluate your grades.

[^3]: This string represents the 'category' variable which identifies the catgeory of assignments within your grades that you wish to evaluate.

[^4]: This string represents the 'command' variable which identifies what data the user would like to return.
  EXCEPTION: When utilizing the Individual class, the 'command' variable represents the assignment name for the individual grade you wish to return.

## Sample Input/Output
<!-- Include screenshots with brief explanations of the images used -->
### Test Cases:
<!-- Written tests for the application. Examples of how to run these tests. -->

#### Credits:
**Project created by Brynne Wright, Jessica Tingley, and Alex Sampalis.** <br />
<br />
Brynne focused primarily on building the **Individual class** and use case implememnation in main. She created the **readme** document for the application with all neccessary contents. <br />
<br />
Jessica focused primarily on building the **Category class** and use case implememnation in main. She implemented the **read/write** and **update** functionality for input and output files and oraganized the gradebook algorithm in main. <br />
<br />
Alex focused primarily on building the **Course class** and all possible outputs from user commands. She implemented the update functionality developed my Jessica to modify input files when utilizing this class. <br />
<br />
***All members collaborated and contributed to all aspects of the application beyond their primary tasks.*** 

#### License:
[License](link)

