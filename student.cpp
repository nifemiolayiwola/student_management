#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;


class Person
{
protected:

    string name;
    int age;

};



class Student : public Person
{
private:

    string id;
    string department;
    double cgpa;


public:

    void addStudent()
    {
        cout << "Student ID: ";
        cin >> id;

        cin.ignore();


        cout << "Student Name: ";
        getline(cin, name);



        while(true)
        {
            cout << "Student Age: ";
            cin >> age;


            if(age > 0)
            {
                break;
            }

            cout << "Invalid age. Age must be greater than 0." << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }


        cin.ignore();


        cout << "Student Department: ";
        getline(cin, department);



        while(true)
        {
            cout << "Student CGPA: ";
            cin >> cgpa;


            if(cgpa >= 0 && cgpa <= 4)
            {
                break;
            }

            cout << "Invalid CGPA." << endl;

        }

    }



    void saveStudent()
    {
        ofstream file("students.txt", ios::app);


        file << id << "|"
            << name << "|"
            << age << "|"
            << department << "|"
            << cgpa << "|"
            << getRank()
            << endl;


        file.close();
    }



    string getRank()
    {
        if(cgpa >= 3.5)
            return "Excellent";

        else if(cgpa >= 3.0)
            return "Very Good";

        else if(cgpa >= 2.0)
            return "Good";

        else
            return "Average";
    }



    void displayStudent()
    {
        cout << left
             << setw(10) << id
             << setw(20) << name
             << setw(10) << age
             << setw(20) << department
             << setw(10) << cgpa
             << setw(15) << getRank()
             << endl;
    }

};