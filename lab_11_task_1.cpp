#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student
{
    private:
    int id;
    string name;
    float gpa;

    public:
    void input()
    {
        cout << "Enter the student ID : ";
        cin >> id;
        cout << "Enter the student name : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the student GPA : ";
        cin >> gpa;
        cout << "--------------------------------" << endl;
    }

    void savetofile(string filename)
    {
        ofstream file;
        file.open(filename, ios::app);
        file << id << ", " << name << ", " << gpa << endl;
        file.close();
    }

    static void display(string filename)
    {
        cout << "Student Record" << endl;
        ifstream file;
        file.open(filename, ios::in);
        if (file.is_open())
        {
			string m;
            while (!(file.eof()))
            {
                getline(file,m);
                cout<<m<<endl;
                cout << "--------------------------------" << endl;
            }
        }
        else
        {
            cout << "Error. File is not opened" << endl;
        }
        cout << "--------------------------------" << endl;
    }
};

int main()
{
    Student s;
    int a = 0;
    while (a != 3)
    {
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Exit" << endl;
        cout << "Choice: ";
        cin >> a;
        cin.ignore();
        if (a == 1)
        {
            s.input();
            s.savetofile("student.txt");
        }
        else if (a == 2)
        {
            s.display("student.txt");
        }
        else if (a == 3)
        {
            cout << "Exiting the program" << endl;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
        cout << "--------------------------------" << endl;
    }
    return 0;
}