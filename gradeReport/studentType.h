#ifndef H_studentType
#define H_studentType

#include <fstream>
#include <string>
#include "personType.h"
#include "courseType.h"

using namespace std;

class studentType: public personType
{
public:
    void setInfo(string fName, string lName, int ID,
                int nOfCourses, bool isTPaid,
                courseType courses[], char courseGrades[]);
    // Function to set the student's infornamtion
    void print(ostream& outF, double tutionRate);
    // function to print the student's grade report
    studentType();
    // default constructor
    int getHoursEnrolled();
    // function to return the credit hours a student is enrolled in
    double getGpa();
    // function to return the gpa
    double bilingAmount(double tuitionRate);
    // function to return the tuition fees.
private:
    void sortCourses();
    // function to sort courses
    int sId;
    int numberOfCourses;

    bool isTuitionPaid;

    courseType courseEnrolled[6];
    char coursesGrade[6];

}; // end class studentType

#endif // H_studentType
