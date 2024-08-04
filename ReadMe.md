# Student Record Management System

## Overview

This project is a follow-up to the previous project available at [cpp-project-2](https://github.com/ralphbotes/cpp-project-2). It demonstrates how to manage student records using C++. This project involves overloading the stream extraction (`>>`) and insertion (`<<`) operators for a `Student` class, reading data from a file, and calculating weighted averages.

## Requirements

1. **Operator Overloading:**
   - Overload the stream extraction operator (`>>`) to read values for each member variable of the `Student` class from a file.
   - Overload the stream insertion operator (`<<`) to print a student's record (name, quiz scores, midterm score, final exam score) and the weighted average.

2. **File Handling:**
   - Use a file named `Student.dat` to read student records. The file will contain data for up to 20 students.

3. **Data:**
   The `Student.dat` file should contain the following records:

    Peter Pan 5 3 45 51
    Wendy Hill 7 5 63 58
    Alice Mokgaba 8 6 51 67
    Precious Petersen 5 7 49 46
    Thumi Tebogo 4 7 69 65

4. **Calculations:**
- Compute the weighted average for each student.
- Calculate the class average (average of all students' weighted averages).

5. **Output:**
- Display each student's record and their weighted average on the screen.
- Display the class average on the screen.

## File Structure

- `Student.h`: Header file containing the `Student` class definition with member variables, functions, and operator overloads.
- `Student.cpp`: Implementation file for the `Student` class.
- `main.cpp`: Contains the main program logic to read from the file, process the data, and display results.
- `Student.dat`: Data file with student records.

## Compilation and Execution

1. Open Code::Blocks.
2. Create a new project and add the above files to the project.
3. Build the project by selecting "Build" from the menu.
4. Run the executable to see the results.

## Notes

- Ensure that `Student.dat` is in the same directory as the executable or adjust the file path in the code as necessary.
- Modify the `Student` class and other files as needed to fit your requirements.