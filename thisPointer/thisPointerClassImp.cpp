#include <iostream>
#include "thisPointerClass.h"

using namespace std;

void thisPointerClass::set(int a, int b,int c)
{
    x = a;
    y = b;
    z = c;
} // end function set

void thisPointerClass::print() const
{
    cout << "x = " << x
         << ", y = " << y
         << ", z = " << z << endl;
} // end function print

thisPointerClass thisPointerClass::updadeXYZ()
{
    x = 2 * x;
    y = y + 2;
    z = z * z;

    return *this;
} // end function updateXYZ

thisPointerClass::thisPointerClass(int a, int b, int c)
{
    x = a;
    y = b;
    z = c;
} // end constructor
