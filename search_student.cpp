#include <iostream>
#include <fstream>

using namespace std;

void searchStudent()
{
    int searchId;
    cout << "Enter the student ID to search: ";
    cin >> searchId;

    ifstream file("students.txt");

    int id;
    string name;
    int age;
    string department;
    double cgpa;
    
    bool found = false;

    while(file >> id >> name >> age >> department >> cgpa)
    {
        if(id == searchId)
        {
            cout << "Student found!" << endl;
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Department: " << department << endl;
            cout << "CGPA: " << cgpa << endl;
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