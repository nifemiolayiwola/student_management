# student_management
/*
 This program allows users to manage student records. It allows users to add, view, search, update, and delete student information. After the user adds the student details, it stores the information in a text file (students.txt).

 It has 6 features
 1. Add: The program gets the student id, student name, student age, department and CGPA from the user.

    Validation:
    Age > 0
    CGPA between 0 and 4
    ID must be unique - 0001, 0002, 0003

 After the user enters the information, the student record is saved in a file.

 2. View: The program reads the student information from the file and displays it in a table.

 3.  Search: It allows the user to find a specific student using the student's ID

 4. Update: It allows the user to update a particular student's information, name, age, department and cgpa.

 5. Delete: it removes a student record from the file

 6. Exit: Ends the program

 Bonus:
 The program automaticallys assigns rank to each student based on their CGPA.

 3.5 to 4.0 - Excellent
 3.49 to 3.0 - Very Good
 2.99 to 2.0 - Good
 Below 2.0 - Average
 

 g++ main.cpp student.cpp add_student.cpp view_student.cpp search_student.cpp update_student.cpp delete_student.cpp -o program

*