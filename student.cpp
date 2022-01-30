#include "student.h"
#include <string>
#include <iostream>
using namespace std;

/*** Student class functions ***/
Student::Student() //Empty constructor to set default values
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    //this->arrDaysToComplete = new int[tableSize];
    for (int i = 0; i < tableSize; i++) this->arrDaysToComplete[i] = 0;
    this->dprog = DegreeProgram::SECURITY; ///selecting 'SECUTIRY' because it is the first value for enum

}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int arrDaysToComplete[], DegreeProgram dprog)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    //this->arrDaysToComplete = new int[tableSize];
    for (int i = 0; i < tableSize; i++) this->arrDaysToComplete[i] = arrDaysToComplete[i];
    this->dprog = dprog;
}

//Destructor
Student::~Student() {}
/*
{
     if (arrDaysToComplete != nullptr)
     {
         delete[] arrDaysToComplete;
         arrDaysToComplete = nullptr;
     }
}
*/


//Accessor functions
string Student::getStudentID()
{
    return this->studentID;
}

string Student::getFirstName()
{
    return this->firstName;
}

string Student::getLastName()
{
    return this->lastName;
}

string Student::getEmailAddress()
{
    return this->emailAddress;
}

int Student::getAge()
{
    return this->age;
}

int* Student::getDaysToComplete() //pointer to an array
{
    return this->arrDaysToComplete;
}

DegreeProgram Student::getDegreeProgram()
{
    return this->dprog;
}


//Mutator functions
void Student::setID(string studentID)
{
    this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Student::setEmail(string emailAddress)
{
    this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setDaysToComplete(int arrDaysToComplete[]) //must do this in a loop, dont want to aassign address from external array in case it changes
{
    for (int i = 0; i < tableSize; i++) this->arrDaysToComplete[i] = arrDaysToComplete[i];

}

void Student::setDegreeProgram(DegreeProgram dprog)
{
    this->dprog = dprog;
}

void Student::print()
{
    cout << this->getStudentID() << '\t'; 
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getAge() << '\t';
    //int * arrDaysToComplete = getDaysToComplete();
    //cout << '\t' << "daysInCourse: " << "{" << arrDaysToComplete[0] << ", " << arrDaysToComplete[1] << ", " << arrDaysToComplete[2] << "}" << '\t';
    cout << this->getDaysToComplete()[0] << ',';
    cout << this->getDaysToComplete()[1] << ',';
    cout << this->getDaysToComplete()[2] << '\t';
    cout << "Degree Program: " << degreeProgramStrings[this->getDegreeProgram()] << endl;
}




