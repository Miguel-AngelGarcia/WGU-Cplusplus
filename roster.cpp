#include <iostream>
#include "roster.h"
#include <string>
using namespace std;

/*
Roster::Roster()
{
     this->maxSize = 0;
     this->lastIndex = -1;
     this->classRosterArray = nullptr;
}

Roster::Roster(int maxSize)
{
     this->maxSize = maxSize;
     this->lastIndex = -1;
     this->classRosterArray = new Student * [maxSize];
}
*/


void Roster::parse(string row)
{  
     /*()
     int parseArr[Student::tableSize];
     DegreeProgram degreeprogram;

     if (lastIndex < maxSize)
     {
         lastIndex++;
     }
  
     this->classRosterArray[lastIndex] = new Student();
     */

    //Parse through the student data strong deliminated by comma
    //read student ID
    //[A1],John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY
    int rhs = row.find(","); //finds comma gets index to help us extract studentID before 1st comma
    string stuID = row.substr(0, rhs);

    //read firstName
    //A1,[John],Smith,John1989@gm ail.com,20,30,35,40,SECURITY
    int lhs = rhs + 1; //moves past the 1st comma
    rhs = row.find(",", lhs);
    string firName = row.substr(lhs, rhs - lhs);

    //read lastName
    //A1,John,[Smith],John1989@gm ail.com,20,30,35,40,SECURITY
    lhs = rhs + 1; //goes past 2nd comma
    rhs = row.find(",", lhs);
    string laName = row.substr(lhs, rhs - lhs);

    //read emailAddress
    //A1,John,Smith,[John1989@gm ail.com],20,30,35,40,SECURITY
    lhs = rhs + 1; //goes past 3rd comma
    rhs = row.find(",", lhs);
    string emAddress = row.substr(lhs, rhs - lhs);

    //read age
    //A1,John,Smith,John1989@gm ail.com,[20]30,35,40,SECURITY
    lhs = rhs + 1; //goes past 4th comma
    rhs = row.find(",", lhs);
    int ageStu = stoi(row.substr(lhs, rhs - lhs)); //stoi allows us to parse an integer

    //read 1st daysInCourse number
    //A1,John,Smith,John1989@gm ail.com,20,[30],35,40,SECURITY
    lhs = rhs + 1;
    rhs = row.find(",", lhs); //goes past 5th comma
    int dInCourse1 = stoi(row.substr(lhs, rhs - lhs));

    //read 2nd daysInCourse number
    //A1,John,Smith,John1989@gm ail.com,20,30,[35],40,SECURITY
    lhs = rhs + 1;
    rhs = row.find(",", lhs); //goes past 6th comma
    int dInCourse2 = stoi(row.substr(lhs, rhs - lhs));

    //read 3rd daysInCourse number
    //A1,John,Smith,John1989@gm ail.com,20,30,35,[40],SECURITY
    lhs = rhs + 1;
    rhs = row.find(",", lhs); //goes past 7th comma
    int dInCourse3 = stoi(row.substr(lhs, rhs - lhs));
 
     //set the days left in course
     //classRosterArray[lastIndex]->setDaysToComplete(parseArr);

     //read degree program
     /*determine what index has unique indentifiers
        at 0, 'SECURITY' and 'SOFTWARE' both have 'S'
        at index 1, 'E' in 'SECURITY,' the 'E' in 'NETWORK' are the same
        at index 2, all three programs have unique letters.
     */
    lhs = rhs + 1; 
    DegreeProgram degProgram = SECURITY; //making this the default value
    if (row.at(lhs+2) == 'T') degProgram = NETWORK;
    else if (row.at(lhs+2) == 'F') degProgram = SOFTWARE;

     /*if (row[lhs] == 'S')
         {
             if (row[lhs + 1] == 'E') classRosterArray[lastIndex]->setDegreeProgram(SECURITY);
             else if (row[lhs + 1] == 'O') classRosterArray[lastIndex]->setDegreeProgram(SOFTWARE);
             else
             {
                 cerr << "INVALID DEGREE PROGRAM! EXITING NOW!" << endl;
                 exit(-1);
             }
         }
         else if (row[lhs] == 'N') classRosterArray[lastIndex]->setDegreeProgram(NETWORK);
         else
         {
             cerr << "INVALID DEGREE PROGRAM! EXITING NOW!" << endl;
             exit(-1);
         }  
     */
    add(stuID, firName, laName, emAddress, ageStu, dInCourse1, dInCourse2, dInCourse3, degProgram);

}


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogam)
{
    int arrDaysToComplete[Student::tableSize];

    arrDaysToComplete[0] = daysInCourse1;
    arrDaysToComplete[1] = daysInCourse2;
    arrDaysToComplete[2] = daysInCourse3;

    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, arrDaysToComplete, degreeprogam);
}

Student* Roster::getStudent(int index)
{
    return classRosterArray[index];
}

void Roster::printAll()
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        cout << classRosterArray[i]-> getStudentID() << '\t';
        cout << classRosterArray[i]-> getFirstName() << '\t';
        cout << classRosterArray[i]-> getLastName() << '\t';
        cout << classRosterArray[i]-> getAge() << '\t';
        cout << classRosterArray[i]-> getDaysToComplete()[0] << '\t'; //want to pull out number at index
        cout << classRosterArray[i]-> getDaysToComplete()[1] << '\t';
        cout << classRosterArray[i]-> getDaysToComplete()[2] << '\t';
        cout << degreeProgramStrings[classRosterArray[i]-> getDegreeProgram()] << endl;
        //we want a string in the output, not a number
    }
    cout << endl;
}

bool Roster::removeStudent(string studentID)
{
    bool found = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            found = true;
            if (i < numStudents - 1)
            {   Student* temp = classRosterArray[i];
                delete this->classRosterArray[i];
                classRosterArray[i] = classRosterArray[lastIndex];
                lastIndex--;
                cout << "Student with ID " << studentID << " was deleted." << endl;
                this-> printAll();
            }
                
        }
   }

   if (!found)
   {
        cout << "Student with ID " << studentID << " not found." << endl;
   }

   return found;
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
    cout << "Printing by degree " << degreeProgramStrings[degreeprogram] << endl;

    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeprogram) classRosterArray[i]->print();
    }
    
    cout << endl;

}

void Roster::printAverageDaysInCourse()
{
    for (int i = 0; i <= Roster::lastIndex; i++) {
        cout << classRosterArray[i]-> getStudentID() << ":";
        cout << (classRosterArray[i]-> getDaysToComplete()[0]
            + classRosterArray[i]-> getDaysToComplete()[1]
            + classRosterArray[i]-> getDaysToComplete()[2]) / 3.0 << endl;
        //dividing by 3.0 turns the results into a double. very important for output!
    }


}

//Note: A valid email should include an at sign ('@') and period ('.') and should not include 
//a space (' ').
void Roster::printInvalidEmails()
{
    //bool invalid = false;
    cout << "Displaying invalid email entries:\n";
    for (int i = 0; i < Roster::lastIndex; i++){
        string emAddress = (classRosterArray[i]->getEmailAddress());

        if ((emAddress.find("@") == string::npos || emAddress.find(".") == string::npos) || (emAddress.find(" ") != string::npos))
                   cout << emAddress << endl;
           }

}


Roster::~Roster()
{
    for (int i = 0; i < numStudents; i++)
    {
        i++;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
    
    //delete thi

     
}
