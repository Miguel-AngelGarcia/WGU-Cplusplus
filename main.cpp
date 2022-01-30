//#pragma once
#include <iostream>
#include "roster.h"
#include <string>
using namespace std;

int main() {

    const int numStudents = 5;

    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@mailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Miguel,Garcia,mgar574@my.wgu.edu,26,90,20,3,SOFTWARE",
    };




    Roster roster;
    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
        

 
    cout << "Printing Roster: " << endl;
    roster.printAll();
    cout << "--Done--" << endl;

    roster.printInvalidEmails();
    cout << "--Done--" << endl;
  
    cout << "Displaying average days left in the course: " << endl;
    for (int i = 0; i < numStudents; i++) {
        roster.printAverageDaysInCourse();
    }
    cout << "--Done--" << endl;

    roster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << "--Done--" << endl;
  
    cout << "Remove student A3: " << endl;
    roster.removeStudent("A3");
    cout << "--Done--" << endl;

    cout << "Printing Roster: " << endl;
    roster.printAll();
    cout << "--Done--" << endl;

    cout << "Remove student A3: " << endl;
    roster.removeStudent("A3");
    cout << "--Done--" << endl;

    system("pause");
    return 0;
}
