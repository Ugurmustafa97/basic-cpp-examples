#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void readCode(ifstream& infile, int list[], int& length, bool& lenCodeOk);

void compareCode(ifstream& infile, ofstream& outfile, int list[], int length);

const int MAX_CODE_SIZE = 250;

int main()
{
    int codeArray[MAX_CODE_SIZE];

    int codeLength;

    bool lengthCodeOk;

    ifstream incode;
    ofstream outcode;

    char inputFile[51];

    char outputFile[51];

    cout << "Enter the input file name: ";
    cin >> inputFile;
    cout << endl;

    incode.open(inputFile);
    if(!incode)
    {
        cout << "Cannot open the input file." << endl;
        return 1;
    } // end if

    cout << "Enter the output file name: ";
    cin >> outputFile;
    cout << endl;

    outcode.open(outputFile);

    readCode(incode, codeArray, codeLength, lengthCodeOk);

    if(lengthCodeOk)
        compareCode(incode, outcode, codeArray, codeLength);
    else
        cout << "Length of the secret code "
             << "must be <= " << MAX_CODE_SIZE
             << endl;

    incode.close();
    outcode.close();

    return 0;
}

void readCode(ifstream& infile, int list[], int& length, bool& lenCodeOk)
{
    int count;

    lenCodeOk = true;

    infile >> length;

    if(length > MAX_CODE_SIZE)
    {
        lenCodeOk = false;
        return;
    } // end if

    for(count = 0; count < length; count++)
        infile >> list[count];
} // end function readCode

void compareCode(ifstream& infile, ofstream& outfile, int list[], int length)
{
    int length2;
    int digit;
    bool codeOk;
    int count;

    codeOk = true;

    infile >> length2;

    if(length != length2)
    {
        cout << "The original code and its copy "
             << "are not of the same length."
             << endl;
        return;
    } // end if

    outfile << "Code Digit    Code Digit Copy"
            << endl;

    for (count = 0; count < length; count++)
    {
        infile >> digit;
        outfile << setw(5) << list[count]
                << setw(17) << digit;

        if(digit != list[count])
        {
            outfile << "  code digits are not the same"
                    << endl;
            codeOk = false;
        } // end if
        else
            outfile << endl;
    } // end for

    if(codeOk)
        outfile << "Message tansmitted OK."
                << endl;
    else
        outfile << "Error in transmission. "
                << "Retransmit!!" << endl;
} // end compareCode
