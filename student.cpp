#include <iostream>
using namespace std;

class Student {
    private:
        int id;
        string name;
        int age;
        string department;
        double cgpa;

    public:
        void addStuddent()
        {
            cout << "Student ID: ";
            cin >> id;
            cin.ignore(); 
            
            // Ignore the newline character left in the buffer
            cout << "Student Name: \n";
            getline(cin, name);
            
            while(true)
            {
                cout << "Student Age: \n";
                cin >> age;

                if(age > 0)
                {
                    return age;
                }
                else
                {
                    cout << "Invalid age. Age must be greater than 0." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

            }
        
            cout << "Student Department: ";
            getline(cin, department);

            while(true)
            {
                cout << "Student CGPA: ";
                cin >> cgpa;

                if(cgpa >= 0.0 && cgpa <= 4.0)
                {
                    return cgpa;
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
        
    }

       
    }
        

}