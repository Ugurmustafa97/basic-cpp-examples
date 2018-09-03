#include <iostream>
#include <string>

using namespace std;

int main()
{
    int number;
    bool done = false;

    string str = "The inpput steam is in the fail state.";

    do
    {
        try
        {
            cout << "Enter an integer: ";
            cin >> number;
            cout << endl;

            if(!cin)
                throw str;

            done =true;
            cout << "Number = " << number << endl;
        } // end try
        catch (string messageStr)
        {
            cout << messageStr << endl;
            cout << "Restoring the input steam." << endl;
            cin.clear();
            cin.ignore(100,'\n');
        } // end catch
    }
    while(!done); // end do while

    return 0;
}
