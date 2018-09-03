#include <iostream>
#include <string>

using namespace std;

int main()
{
    int dividend, divisor = 1, quotient;

    string inpStr = "The input stream is in the fail state.";

    try
    {
        cout << "Enter the dividend: ";
        cin >> dividend;
        cout << endl;

        cout << "Enter the divisor: ";
        cin >> divisor;
        cout << endl;

        if(divisor == 0)
            throw divisor;
        else if(divisor < 0)
            throw string("Negative divisor.");
        else if(!cin)
            throw inpStr;

        quotient = dividend / divisor;

        cout << "Quotient = " << quotient
             << endl;
    } //end try
    catch(int x)
    {
        cout << "Division by " << x
             << endl;
    } // end catch
    catch(string s)
    {
        cout << s << endl;
    } // end catch

    return 0;
}// end main
