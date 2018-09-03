#include <iostream>
#include <string>

using namespace std;

class divisionByZero
{
public:
    divisionByZero()
    {
        message = "Divison by zero";
    }
    divisionByZero(string str)
    {
        message =str;
    }
    string what()
    {
        return message;
    }
private:
    string message;
}; // end class
