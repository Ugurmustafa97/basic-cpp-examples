#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

void initialize(int& lc, int list[]);

void copyText(ifstream& intext, ofstream& outtext, char& ch, int list[]);

void characterCount(char ch, int list[]);

void writeTotal(ofstream& outtext, int lc, int list[]);

int main()
{
    int lineCount;
    int letterCount[26];
    char ch;
    ifstream infile;
    ofstream outfile;

    infile.open("textin.txt");

    if(!infile)
    {
        cout << "Cannot open the input file."
             << endl;
        return 1;
    } // end if

    outfile.open("textout.out");

    initialize(lineCount,letterCount);

    infile.get(ch);

    while(infile)
    {
        copyText(infile, outfile, ch, letterCount);
        lineCount++;
        infile.get(ch);
    } // end while

    writeTotal(outfile, lineCount, letterCount);

    infile.close();
    outfile.close();

    return 0;
}

void initialize(int& lc, int list[])
{
    int j;
    lc = 0;

    for(j = 0; j < 26; j++)
        list[j] = 0;
} // end function initialize

void copyText(ifstream& intext, ofstream& outtext, char& ch, int list[])
{
    while(ch != '\n')
    {
        outtext << ch;
        characterCount(ch, list);
        intext.get(ch);
    } //end while
    outtext << ch;
} // end funciton copyText

void characterCount(char ch, int list[])
{
    int index;

    ch = toupper(ch);

    index = static_cast<int>(ch) - static_cast<int>('A');

    if(0 <= index && index < 26)
        list[index]++;
} // end function characterCount

void writeTotal(ofstream& outtext, int lc, int list[])
{
    int index;
    outtext << endl << endl;
    outtext << "The number of lines = " << lc << endl;

    for(index = 0; index < 26; index++)
        outtext << static_cast<char>(index + static_cast<int>('A'))
                << " count = " << list[index] << endl;
} // end function writeTotal
