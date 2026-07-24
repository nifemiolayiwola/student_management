#include <iostream>
#include <fstream>

using namespace std;

void updateStudent()
{
    int updateId;
    cout << "Enter the student ID to update: ";
    cin >> updateId;

    ifstream file("students.txt");
    ofstream tempFile("temp.txt");

    int id;
    string name;
    int age;
    string department;
    double cgpa;

    bool found = false;

    while(file >> id >> name >> age >> department >> cgpa)
    {
        if(id == updateId)
        {
            found = true;

            cout << "Enter new details for the student:" << endl;
            cout << "Student Name: ";
            cin.ignore();
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

            tempFile << id << " " << name << " " << age << " " << department << " " << cgpa << endl;
        }
        else
        {
            tempFile << id << " " << name << " " << age << " " << department << " " << cgpa << endl;
        }
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