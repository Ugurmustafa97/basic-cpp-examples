#include <iostream>
#include "divisionByZero.h"

using namespace std;

int main()
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
    catch(divisionByZero divByZeroObj)
    {
        cout << "In the divisionByZero "
             << "catch block: "
             << divByZeroObj.what() << endl;
    } // end catch

    return 0;
}
