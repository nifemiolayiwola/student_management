#include <iostream>
#include <fstream>
#include <limits>

using namespace std;


string calculateRank(string cgpa)
{
    double value = 0;


    if(cgpa == "4" || cgpa == "4.0" || cgpa == "3.5" || cgpa == "3.6" || cgpa == "3.7" || cgpa == "3.8" || cgpa == "3.9")
    {
        return "Excellent";
    }
    else if(cgpa == "3.0" || cgpa == "3.1" || cgpa == "3.2" || cgpa == "3.3" || cgpa == "3.4")
    {
        return "Very Good";
    }
    else if(cgpa == "2.0" || cgpa == "2.1" || cgpa == "2.2" || cgpa == "2.3" || cgpa == "2.4" || cgpa == "2.5" || cgpa == "2.6" || cgpa == "2.7" || cgpa == "2.8" || cgpa == "2.9")
    {
        return "Good";
    }
    else
    {
        return "Average";
    }
}



void updateStudent()
{
    string updateId;

    cout << "Enter the student ID to update: ";
    cin >> updateId;


    ifstream file("students.txt");
    ofstream tempFile("temp.txt");


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



        if(id == updateId)
        {
            found = true;


            cout << "\nEnter new details for the student:" << endl;


            cin.ignore();


            cout << "Student Name: ";
            getline(cin, name);


            cout << "Student Age: ";
            getline(cin, age);


            cout << "Student Department: ";
            getline(cin, department);


            cout << "Student CGPA: ";
            getline(cin, cgpa);


            rank = calculateRank(cgpa);
        }



        tempFile << id << "|"
                 << name << "|"
                 << age << "|"
                 << department << "|"
                 << cgpa << "|"
                 << rank
                 << endl;
    }



    file.close();
    tempFile.close();



    if(found)
    {
        remove("students.txt");
        rename("temp.txt", "students.txt");

        cout << "Student updated successfully!" << endl;
    }

    else
    {
        remove("temp.txt");

        cout << "Student not found." << endl;
    }
}