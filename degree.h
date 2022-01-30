/*
enum DegreeProgram {SECURITY, NETWORK,  SOFTWARE};
DegreeProgram degreeProgram;
*/

#pragma once
#include <iostream>
#include <string>

//Define an enumerated data type DegreeProgram, data type values SECURITY, NETWORK and SOFTWARE
enum DegreeProgram {
    SECURITY = 0,
    NETWORK = 1,
    SOFTWARE = 2
};

//will be usiung degree type as index
static const std::string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };