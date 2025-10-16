[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/7uEBlwGZ)

# Student Management System

This Student Management System is designed to manage student information, including personal details, course details, grades, and GPAs. It allows for the input of student data, tracking of semesters, and calculation of GPAs and CGPAs based on the grades entered.

## Features

- Input student personal information (name, date of birth, registration number, college details, course, and semester).
- Input marks and credit units for multiple course units.
- Calculate GPA for each semester.
- Calculate CGPA across multiple semesters.
- Age calculation based on date of birth.

## Algorithm

1. **Initialize Student Class:**
   - Prompt user for name, date of birth, registration number, college information, course, and current semester.
   
2. **Calculate Age:**
   - Get current date and calculate the age of the student based on the date of birth provided.

3. **Track Current Semester:**
   - For each semester, prompt for the number of course units.
   - For each course unit:
     - Prompt for marks and validate input.
     - Prompt for credit units and validate input.
     - Calculate the grade point based on the marks.
     - Accumulate total GP times CU and credit units.
   - Calculate and output GPA for the semester.
   - Update the cumulative GPA and calculate CGPA.

4. **Output Results:**
   - Display the calculated age, GPA for each semester, and final CGPA.

## Flowchart

For a visual representation of the process, please refer to the flowchart below:

[Open Flowchart](flowchart.svg)
## UML Diagram
[Open UML Diagram](UML_Diagram.svg)

## Usage

To use the system:

1. Compile and run the program.
2. Follow the prompts to input the required information.
3. Review the calculated results for GPA and CGPA at the end.

## Requirements

- C++ Compiler (C++11 or later recommended)

## License

This project is licensed under the MIT License. Feel free to use and modify as needed.
