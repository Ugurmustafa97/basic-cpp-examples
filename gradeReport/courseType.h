#ifndef H_courseType
#define H_courseType

#include <fstream>
#include <string>

using namespace std;

class courseType
{
public:
    void setCourseInfo(string cName, string cNo, int credits);
    // function to set the course information
    void print(ostream& outF);
    // function to set the course information
    int getCredits();
    // function to return the credit hours
    string getCourseNumber();
    // function to return the course number
    string getCourseName();
    // function to return the course name
    courseType(string cName = "", string cNo = "", int credits = 0);
    // constructor

private:
    string courseName;
    string courseNo;
    int courseCredits;
}; // end courseType

#endif // H_courseType



