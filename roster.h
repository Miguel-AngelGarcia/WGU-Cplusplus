#pragma once
#include "student.h"
#include <iostream>
#include <string>
#include <iomanip>

class Roster
{
private:
    int lastIndex = -1; //when we add the first student we want the index to start at 0
    const static int numStudents = 5;
    Student* classRosterArray[numStudents]; //array of pointers to hold data

public:  
    /*
    int lastIndex;
    int maxSize = 5;
    Student** classRosterArray; //array of pointers to hold data
    */ 

    //default constructor
    //Roster();
    //Student*();
    //Roster(int maxSize);


    void parse(string row);
    void add(
        string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeprogram
    );


    Student* getStudent(int index);
    void printAll();
    bool removeStudent(string studentID);
    //void printAverageDaysInCourse(string studentID);
    void printAverageDaysInCourse();
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeprogram);
    ~Roster();
};
