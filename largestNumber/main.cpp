#include <iostream>

using namespace std;

double larger(double x, double y);

int main()
{
    double num;
    double max;
    int count;

    cout << "Enter 10 positive numbers: " << endl;
    //cin >> num;
    max = 0;

    for(count = 1; count <=10 ;count++)
    {
        cin >> num;
        max = larger(max, num);
    }// end for

    cout << "The largest number is " << max
         << endl;

    return 0;
} // end main function

double larger(double x, double y)
{
    if(x >= y)
        return x;
    else
        return y;
} // end function larger

