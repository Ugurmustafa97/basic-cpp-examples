#include <iostream>
#include <iomanip>

using namespace std;

const int N = 20;

void initialize(int& zeroCount, int& oddCount, int& evenCount);
void getNumber(int& num);
void classifyNumber(int num, int& zeroCount, int& oddCount,
                    int& evenCount);
void printResults(int zeroCount, int oddCount, int evenCount);

int main()
{
    int counter;
    int number;
    int zeros;
    int odds;
    int evens;

    initialize(zeros,odds,evens);
    cout << "Please enter " << N << "numbers: "
        << endl;
    cout << "The numbers you entered are: "
        << endl;

    for(counter = 1; counter <= N; counter++)
    {
        getNumber(number);
        cout << number << " ";
        classifyNumber(number, zeros, odds, evens);

    } // end for

    cout << endl;
    printResults(zeros,odds, evens);

    return 0;
}

void initialize(int& zeroCount, int& oddCount, int& evenCount)
{
    zeroCount = 0;
    oddCount = 0;
    evenCount = 0;
} // end function initialize

void getNumber(int& num)
{
    cin >> num;
} // end function getNumber

void classifyNumber(int num, int&  zeroCount, int& oddCount,
                    int& evenCount)
{
    switch(num % 2)
    {
    case 0:
        evenCount++;
        if(num == 0)
            zeroCount++;
        break;
    case 1:
    case -1:
        oddCount++;
    } // end switch
} // end function classifyNumber

void printResults(int zeroCount, int oddCount, int evenCount)
{
    cout << "There are " << evenCount << " evens, "
         << "which includes " << zeroCount << " zeros"
         << endl;
    cout << "The number of odd numbers is: " << oddCount
         << endl;
} // end printResults
