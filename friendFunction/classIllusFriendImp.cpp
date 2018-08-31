#include <iostream>
#include "classIllusFriend.h"

using namespace std;

void classIllusFriend::print()
{
    cout << "In class classIllusFriend: x = " << x << endl;
} // end function print

void classIllusFriend::setx(int a)
{
    x = a;
} // end function setx

void two(classIllusFriend cIFObject)
{
    classIllusFriend localTwoObject;

    localTwoObject.x = 45;

    localTwoObject.print();

    cout << "In Friend Function two "
         << "accesing private member variable "
         << "x = " << localTwoObject.x
         << endl;

    cIFObject.x = 88;

    cIFObject.print();

    cout << "In Frienf Function two "
         << "accesing private member variable "
         << "x = " << cIFObject.x << endl;
} // end friend two
