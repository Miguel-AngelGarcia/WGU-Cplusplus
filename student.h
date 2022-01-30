//The class declaration goes into the header file. 
//It is important that you add the #ifndef  include guards.

//#indef
/*
Create each of the following functions in the Student class:

a.  an accessor (i.e., getter) for each instance variable from part D1
b.  a mutator (i.e., setter) for each instance variable from part D1
c.  All external access and changes to any instance variables of the Student class must 
    be done using accessor and mutator functions.
d.  constructor using all of the input parameters provided in the table
e.  print() to print specific student data
*/
/*
#include <string>
#include<iostream>
#include "degree.h"

using namespace std;



class StudentVariables
{
    int studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse;
    DegreeProgram degreeProgam;
};

//Default Constructor
StudentVariables::StudentVariables(){
    firstName = "";
    lastName = "";

}


//Mutators

void ser
*/
#pragma once
#include "degree.h"
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

/*** Student class definition ***/
class Student
{
public:
    const static int tableSize = 3;

private: //needs to be privat public or protected??~
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    //int * arrDaysToComplete;
    int arrDaysToComplete[tableSize];
    DegreeProgram dprog;
  
public:
    //default constructor
    Student();
  
    //full constructor
    Student(
        string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int arrDaysToComplete[],
        DegreeProgram dprog
    );

    //destuctor
    ~Student();

   //accessors for each instance
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysToComplete();
    DegreeProgram getDegreeProgram();

   //mutators
    void setID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string emailAddress);
    void setAge(int age);
    void setDaysToComplete(int arrDaysToComplete[]);
    void setDegreeProgram(DegreeProgram dprog);
    void print(); 

};