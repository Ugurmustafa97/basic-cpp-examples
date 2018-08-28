#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "courseType.h"

using namespace std;

void courseType::setCourseInfo(string cName, string cNo, int credits)
{
    courseName = cName;
    courseNo = cNo;
    courseCredits = credits;
} // end function setCourseInfo

void courseType::print(ostream& outF)
{
    outF << left;
    outF << setw(8) << courseNo << "  ";
    outF << setw(15) << courseName;
    outF << right;
    outF << setw(3) << courseCredits << "  ";
} // end fuction print

courseType::courseType(string cName, string cNo, int credits)
{
    courseName = cName;
    courseNo = cNo;
    courseCredits = credits;
} // end constructor

int courseType::getCredits()
{
    return courseCredits;
} // end function getCredits

string courseType::getCourseNumber()
{
    return courseNo;
} // end function getCourseNumber

string courseType::getCourseName()
{
    return courseName;
} // end getCourseName
