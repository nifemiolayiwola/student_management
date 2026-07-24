#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


void viewStudent()
{
    ifstream file("students.txt");


    if(!file)
    {
        cout << "Error opening file." << endl;
        return;
    }


    string id;
    string name;
    string age;
    string department;
    string cgpa;
    string rank;



    cout << left
         << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Age"
         << setw(20) << "Department"
         << setw(10) << "CGPA"
         << setw(15) << "Rank"
         << endl;


    cout << "--------------------------------------------------------------------------" << endl;



    while(getline(file, id, '|'))
    {
        getline(file, name, '|');
        getline(file, age, '|');
        getline(file, department, '|');
        getline(file, cgpa, '|');
        getline(file, rank);



        cout << left
             << setw(10) << id
             << setw(20) << name
             << setw(10) << age
             << setw(20) << department
             << setw(10) << cgpa
             << setw(15) << rank
             << endl;
    }


    file.close();
}