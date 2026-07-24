#include <iostream>
#include <fstream>
#include <limits>

using namespace std;


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


    bool found = false;



    while(getline(file, id, '|'))
    {
        getline(file, name, '|');
        getline(file, age, '|');
        getline(file, department, '|');
        getline(file, cgpa);



        if(id == updateId)
        {
            found = true;


            cout << "\nEnter new details for the student:" << endl;


            cin.ignore();


            cout << "Student Name: ";
            getline(cin, name);



            while(true)
            {
                cout << "Student Age: ";
                cin >> age;


                if(age != "0")
                {
                    break;
                }

                else
                {
                    cout << "Invalid age. Age must be greater than 0." << endl;
                }
            }



            cin.ignore();


            cout << "Student Department: ";
            getline(cin, department);



            cout << "Student CGPA: ";
            cin >> cgpa;

        }



        tempFile << id << "|"
                 << name << "|"
                 << age << "|"
                 << department << "|"
                 << cgpa << endl;
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