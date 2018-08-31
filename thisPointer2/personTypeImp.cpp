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

personType& personType::setLastName(string last)
{
    lastName = last;

    return *this;
} // end setLastName

personType& personType::setFirstName(string first)
{
    firstName = first;

    return *this;
} // end setFirstName

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
