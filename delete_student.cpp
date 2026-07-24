#include <iostream>
#include <fstream>

using namespace std;

void deleteStudent()
{
    string deleteId;

    cout << "Enter the student ID to delete: ";
    cin >> deleteId;


    ifstream file("students.txt");
    ofstream tempFile("temp.txt");


    string id;
    string name;
    string age;
    string department;
    string cgpa;


    bool found = false;


    while(getline(file, id, '|'))
    {
        getline(file, name, '|');
        getline(file, age, '|');
        getline(file, department, '|');
        getline(file, cgpa);


        if(id == deleteId)
        {
            found = true;

            cout << "Student with ID "
                 << deleteId
                 << " deleted successfully!"
                 << endl;

            continue; // do not copy this student
        }


        tempFile << id << "|"
                 << name << "|"
                 << age << "|"
                 << department << "|"
                 << cgpa << endl;
    }


    file.close();
    tempFile.close();



    remove("students.txt");
    rename("temp.txt", "students.txt");



    if(!found)
    {
        cout << "Student with ID "
             << deleteId
             << " not found."
             << endl;
    }
}