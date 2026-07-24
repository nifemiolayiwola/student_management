#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

class Student 
{
    private:
        string id;
        string name;
        int age;
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
                else
                {
                    cout << "Invalid age. Age must be greater than 0." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

            }
            cin.ignore();
        
            cout << "Student Department: ";
            getline(cin, department);

            while(true)
            {
                cout << "Student CGPA: ";
                cin >> cgpa;

                if(cgpa >= 0.0 && cgpa <= 4.0)
                {
                    break;
                }
                else
                {
                    cout << "Invalid CGPA. CGPA must be between 0.0 and 4.0." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }

        void saveStudent()
        {
            ofstream file("students.txt", ios::app);
            if (!file)
            {
                cout << "Error opening file." << endl;
                return;
            }

            file << id << "|" << name << "|" << age << "|" << department << "|" << cgpa << endl;
            file.close();
        }

        void displayStudent()
        {
            cout << left << setw(10) << id
                << setw(20) << name
                << setw(10) << age
                << setw(20) << department
                << setw(10) << cgpa << endl;
        }

       
};
        
