#include <iostream>
#include <map>

using namespace std;

class Student
{
private:
    string name;
    int id;
    int level;
    int gpa;

public:
    void setName()
    {
        cout << "enter stud name: \n";
        cin.ignore();
        getline(cin, name);
    }

    void addStudentInfo()
    {
        cout << "enter id: "; cin >> id;
        cout << "enter level: "; cin >> level;
        cout << "enter gpa: "; cin >> gpa;
    }

    string getName()
    {
        return name;
    }

    int getGpa()
    {
        return gpa;
    }
};

class Director
{
private:
    Student* stud;
    int input;
    map<string, Student>data;

public:
    void createStud()
    {
        stud = new Student;
        stud->setName();
    }

    void addStudentToData()
    {
        string na = stud->getName();
        data[na].addStudentInfo();
    }

    void getInput()
    {
        cout << "choose here..\n";
        cout << "1: to add new student\n";
        cout << "2: to get a student gpa\n";
        cout << "0: to exit..\n";
        cin >> input;

    }

    void work()
    {
        getInput();
       do
       {
           if(input == 1)
           {
               createStud();
               addStudentToData();
               getInput();
           }
           else if(input == 2)
           {
               string stName;
               cout << "enter student name: \n";
               cin.ignore();
               getline(cin, stName);
               cout << "GPA for student: " << stName << " is " << data[stName].getGpa() << endl;
               getInput();
           }

       }while (input != 0);
    }

};




int main()
{
    Director dr;
    dr.work();
    return 0;
}
