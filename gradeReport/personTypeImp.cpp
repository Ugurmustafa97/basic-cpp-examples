#include <iostream>
#include <string>
#include "personType.h"

using namespace std;

void personType::print() const
{
    cout << firstName << " " << lastName;
} // end function print

void personType::setName(string first, string last)
{
    firstName = first;
    lastName = last;
} // end function setName

string personType::getFirstName() const
{
    return firstName;
} // end getFirstName

string personType::getLastName() const
{
    return lastName;
} // end function getLastName

personType::personType(string first, string last)
{
    firstName = first;
    lastName = last;
} // end constructor
