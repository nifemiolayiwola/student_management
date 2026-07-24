#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void viewStudent()
{
    ifstream file("students.txt");

    if (!file)
    {
        cout << "Unable to open file." << endl;
        return;
    }

    string id;
    string name;
    string age;
    string department;
    string cgpa;

    cout << left
         << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Age"
         << setw(20) << "Department"
         << setw(10) << "CGPA" << endl;

    cout << "--------------------------------------------------------------------------" << endl;

    while (getline(file, id, '|'))
    {
        getline(file, name, '|');
        getline(file, age, '|');
        getline(file, department, '|');
        getline(file, cgpa);

        cout << left
             << setw(10) << id
             << setw(20) << name
             << setw(10) << age
             << setw(20) << department
             << setw(10) << cgpa << endl;
    }

    file.close();
}