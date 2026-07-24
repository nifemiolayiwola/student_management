#include <iostream>
#include <fstream>

using namespace std;

void searchStudent()
{
    string searchId;

    cout << "Enter the student ID to search: ";
    cin >> searchId;


    ifstream file("students.txt");


    string id;
    string name;
    string age;
    string department;
    string cgpa;
    string rank;


    bool found = false;


    while(getline(file, id, '|'))
    {
        getline(file, name, '|');
        getline(file, age, '|');
        getline(file, department, '|');
        getline(file, cgpa, '|');
        getline(file, rank);


        if(id == searchId)
        {
            cout << "\nStudent Found!" << endl;

            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Department: " << department << endl;
            cout << "CGPA: " << cgpa << endl;
            cout << "Rank: " << rank << endl;


            found = true;
            break;
        }
    }


    if(!found)
    {
        cout << "Student not found." << endl;
    }


    file.close();
}