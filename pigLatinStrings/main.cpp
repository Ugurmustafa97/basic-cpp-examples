#include <iostream>
#include <string>

using namespace std;

bool isVowel(char ch);

string rotate(string pStr);

string pigLatinString(string pStr);

int main()
{
    string str;

    cout << "Enter a string: ";
    cin >> str;
    cout << endl;

    cout << "The pig Latin form of " << str << "is: "
         << pigLatinString(str) << endl;

    return 0;
}


bool isVowel(char ch)
{
    switch(ch)
    {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'Y':
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
        return true;
    default:
        return false;
    } // end switch
} // end function isVowel

string rotate(string pStr)
{
    string::size_type len = pStr.length();

    string rStr;

    rStr = pStr.substr(1, len -1) + pStr[0];

    return rStr;
} // end function rotate

string pigLatinString(string pStr)
{
    string::size_type len;

    bool foundVowel;

    string::size_type counter;

    if(isVowel(pStr[0]))
        pStr = pStr + "-way";
    else
    {
        pStr = pStr + '-';
        pStr = rotate(pStr);

        len = pStr.length();
        foundVowel = false;

        for(counter = 1; counter < len - 1;
            counter++)
        {
            if(isVowel(pStr[0]))
            {
                foundVowel = true;
                break;
            } // end if
            else
                pStr = rotate(pStr);
        } // end for

        if(!foundVowel)
            pStr = pStr.substr(1,len) + "-way";
        else
            pStr = pStr + "ay";
    } // end else

    return pStr;
} // end function pigLatinString
