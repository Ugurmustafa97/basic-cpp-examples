#include <iostream>
#include "divisionByZero.h"

using namespace std;

void doDivision() throw (divisionByZero);

int main()
{
    try
    {
        doDivision();
    }
    catch(divisionByZero divByZeroObj)
    {
        cout << "In main: "
             << divByZeroObj.what() << endl;
    }
}

void doDivision() throw (divisionByZero)
{
    int dividend, divisor, quotient;

    try
    {
        cout << "Enter the dividend: ";
        cin >> dividend;
        cout << endl;

        cout << "Enter the divisor: ";
        cin >> divisor;
        cout << endl;

        if(divisor == 0)
            throw divisionByZero("Found divison by zero");

        quotient = dividend / divisor;
        cout << "Quotient = " << quotient
             << endl;
    } // end try
    catch(divisionByZero)
    {
        throw;
    } // end catch
} // end function
