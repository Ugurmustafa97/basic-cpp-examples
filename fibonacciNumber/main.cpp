#include <iostream>

using namespace std;

int main()
{
    int previous1;
    int previous2;
    int current;
    int counter;
    int nthFibonacci;

    cout << "Write the first number: " ;
    cin >> previous1;
    cout << endl;

    cout << "Write the second number: ";
    cin >> previous2;
    cout << endl;

    cout << "The first Fibonacci Numbers are"
         << previous1 << "and " << previous2
         << endl;

    cout << "Enter the position of the desired"
         << "Fibonacci Number: ";
    cin >> nthFibonacci;
    cout << endl;

    if(nthFibonacci == 1)
        current = previous1;
    else if(nthFibonacci == 2)
        current = previous2;
    else
    {
        counter = 3;
        while(counter <= nthFibonacci)
        {
            current = previous1 + previous2;
            previous1 = previous2;
            previous2 = current;
            counter++;
        } // end while
    } // end else
    cout << "nth Fibonacci number is: "
         << current << endl;

    return 0;
} // end main
