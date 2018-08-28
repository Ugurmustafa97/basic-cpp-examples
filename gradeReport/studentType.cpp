#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "personType.h"
#include "courseType.h"
#include "studentType.h"

using namespace std;

void studentType::setInfo(string fName, string lName, int ID,
                        int nOfCourses, bool isTPaid,
                        courseType courses[], char cGrades[])
{
    int i;

    setName(fName, lName);

    sId = ID;
    isTuitionPaid = isTPaid;
    numberOfCourses = nOfCourses;

    for (i = 0; i < numberOfCourses; i++)
    {
        courseEnrolled[i] = courses[i];
        coursesGrade[i] = cGrades[i];
    } // end for

    sortCourses();

} // end function setInfo

studentType::studentType()
{
    numberOfCourses = 0;
    sId = 0;
    isTuitionPaid = false;

    for (int i = 0; i < 6; i++)
        coursesGrade[i] = '*';
} // end default constructor

void studentType::print(ostream& outF, double tuitionRate)
{
    int i;

    outF << "Student Name: " << getFirstName()
         << " " << getLastName() << endl;

    outF << "Student ID: " << sId << endl;

    outF << "Number of courses enrolled: "
         << numberOfCourses << endl;
    outF << endl;

    outF << left;
    outF << "Course No" << setw(15) << " Course Name"
         << setw(8) << "Credits"
         << setw(6) << "Grade" << endl;

    outF << right;
    for (i = 0; i < numberOfCourses; i++)
    {
        courseEnrolled[i].print(outF);

        if (isTuitionPaid)
            outF << setw(4) << coursesGrade[i] << endl;
        else
            outF << setw(4) << "***" << endl;
    } // end for
    outF << endl;

    outF << "Total number of credit hours: "
         << getHoursEnrolled() << endl;

    outF << fixed << showpoint << setprecision(2);

    if(isTuitionPaid)
        outF << "Mid-Semester GPA: " << getGpa() << endl;
    else
    {
        outF << "*** Grades are being held for not paying "
             << "the tution. ***" << endl;
        outF << "Amount Due: $" << bilingAmount(tuitionRate)
             << endl;
    }

    outF << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl
         << endl;
} // end function print

int studentType::getHoursEnrolled()
{
    int totalCredits = 0;
    int i;

    for(i = 0; i < numberOfCourses; i++)
        totalCredits += courseEnrolled[i].getCredits();

    return totalCredits;
} // end getHoursEnrolled

double studentType::bilingAmount(double tuitionRate)
{
    return tuitionRate * getHoursEnrolled();
} // end billingAmount

double studentType::getGpa()
{
    int i;
    double sum = 0.0;

    for(i = 0; i < numberOfCourses; i++)
    {
        switch (coursesGrade[i])
        {
        case 'A':
            sum += courseEnrolled[i].getCredits() * 4;
            break;
        case 'B':
            sum += courseEnrolled[i].getCredits() * 3;
            break;
        case 'C':
            sum += courseEnrolled[i].getCredits() * 2;
            break;
        case 'D':
            sum += courseEnrolled[i].getCredits() * 1;
            break;
        case 'F':
            sum += courseEnrolled[i].getCredits() * 0;
            break;
        default:
            cout << "Invalid Course Grade." << endl;
        } // end switch
    } // end for

    return sum / getHoursEnrolled();
} // end function getGpa

void studentType::sortCourses()
{
    int i, j;
    int minIndex;
    courseType temp;
    char tempGrade;
    string course1;
    string course2;

    for (i = 0; i < numberOfCourses - 1; i++)
    {
        minIndex = i;

        for(j = i + 1; j < numberOfCourses; j++)
        {
            course1 =
                courseEnrolled[minIndex].getCourseNumber();
            course2 = courseEnrolled[j].getCourseNumber();

            if(course1 > course2)
                minIndex = j;
        } // end for

        temp = courseEnrolled[minIndex];
        courseEnrolled[minIndex] = courseEnrolled[i];
        courseEnrolled[i] = temp;

        tempGrade = coursesGrade[minIndex];
        coursesGrade[minIndex] = coursesGrade[i];
        coursesGrade[i] = tempGrade;
    } // end for
} // end sortCourses

