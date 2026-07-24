#include <iostream>
#include <fstream>

using namespace std;
void deleteStudent()
{
    int deleteId;
    cout << "Enter the student ID to delete: ";
    cin >> deleteId;

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
        if(id == deleteId)
        {
            found = true;
            cout << "Student with ID " << deleteId << " deleted successfully!" << endl;
        }
        else
        {
            tempFile << id << " " << name << " " << age << " " << department << " " << cgpa << endl;
        }
    }

    if(!found)
    {
        cout << "Student with ID " << deleteId << " not found." << endl;
    }

    file.close();
    tempFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");
}