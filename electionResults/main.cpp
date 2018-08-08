#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int NO_OF_CANDIDATES = 6;
const int NO_OF_REGIONS = 4;

void getCandidatesName(ifstream& inp, string cNames[], int noOfRows);

void sortCandidatesName(string cNames[], int noOfRows);

void initialize(int vbRegion[][NO_OF_REGIONS], int tVotes[],
                int noOfRows);

int binSearch(string cNames[], int noOfRows, string name);

void processVotes(ifstream& inp, string cNames[],
                  int vbRegion[][NO_OF_REGIONS], int noOfRows);

void addRegionsVote(int vbRegion[][NO_OF_REGIONS], int tVotes[],
                    int noOfRows);

void printHeading();

void printResults(string cNames[], int vbRegion[][NO_OF_REGIONS],
                    int tVotes[], int noOfRows);

int main()
{
    string candidatesName[NO_OF_CANDIDATES];
    int votesByRegion[NO_OF_CANDIDATES][NO_OF_REGIONS];
    int totalVotes[NO_OF_CANDIDATES];
    ifstream infile;

    infile.open("candData.txt");
    if(!infile)
    {
        cout << "Input file candData.txt does "
             << "not exist." << endl;
        return 1;
    } // end if

    getCandidatesName(infile, candidatesName,
                      NO_OF_CANDIDATES);
    sortCandidatesName(candidatesName,NO_OF_CANDIDATES);

    infile.close();
    infile.clear();

    infile.open("voteData.txt");
    if(!infile)
    {
        cout << "Input file voteData.txt does "
             << "not exist." << endl;
        return 1;
    } // end if

    initialize(votesByRegion, totalVotes, NO_OF_CANDIDATES);
    processVotes(infile, candidatesName,
                 votesByRegion, NO_OF_CANDIDATES);
    addRegionsVote(votesByRegion, totalVotes,
                   NO_OF_CANDIDATES);
    printHeading();
    printResults(candidatesName, votesByRegion,
                 totalVotes, NO_OF_CANDIDATES);

    return 0;
}

void getCandidatesName(ifstream& inp, string cNames[],
                        int noOfRows)
{
    int i;

    for(i = 0; i < noOfRows; i++)
        inp >> cNames[i];
} // end function getCandidatesName

void sortCandidatesName(string cNames[], int noOfRows)
{
    int i, j;
    int min;

        // selection sort
    for(i = 0; i < noOfRows - 1; i++)
    {
        min = i;

        for(j = i +1; j < noOfRows; j++)
            if(cNames[j] < cNames[min])
                min = j;

        cNames[i].swap(cNames[min]);
    } // end for

} // end function sortCandidatesName

void initialize(int vbRegion[][NO_OF_REGIONS], int tVotes[],
                int noOfRows)
{
    int i, j;

    for(i = 0; i < noOfRows; i++)
        for(j = 0; j < NO_OF_REGIONS; j++)
            vbRegion[i][j] = 0;

    for(i = 0; i < noOfRows; i++)
        tVotes[i] = 0;
} // end function initialize

int binSearch(string cNames[], int noOfRows, string name)
{
    int first, last, mid;
    bool found;
    first = 0;
    last = noOfRows - 1;
    found = false;

    while(!found && first <= last)
    {
        mid = (first + last) / 2;

        if(cNames[mid] == name)
            found = true;
        else if(cNames[mid] > name)
            last = mid - 1;
        else
            first = mid + 1;
    } // end while

    if(found)
        return mid;
    else
        return -1;
} // end function binSearch

void processVotes(ifstream& inp, string cNames[],
                  int vbRegion[][NO_OF_REGIONS], int noOfRows)
{
    string candName;
    int region;
    int noOfVotes;
    int loc;

    inp >> candName >> region >> noOfVotes;

    while(inp)
    {
        loc = binSearch(cNames, noOfRows, candName);

        if(loc != -1)
            vbRegion[loc][region -1] = vbRegion[loc][region -1] + noOfVotes;

        inp >> candName >> region >> noOfVotes;
    } // end while
} // end function processVotes

void addRegionsVote(int vbRegion[][NO_OF_REGIONS], int tVotes[],
                    int noOfRows)
{
    int i,j;

    for(i = 0; i < noOfRows; i++)
        for(j = 0; j < NO_OF_REGIONS; j++)
            tVotes[i] = tVotes[i] + vbRegion[i][j];
} // end function addRegionsVote

void printHeading()
{
    cout << "      -------------Election Result----------"
         << "----" << endl << endl;
    cout << "Candidate                  Votes" << endl;
    cout << "Name        Region1   Region2   Region3   "
         << "Region4    Total" << endl;
    cout << "---------   -------   -------   -------   "
         << "-------   -------" << endl;
} // end function printHeading

void printResults(string cNames[], int vbRegion[][NO_OF_REGIONS],
                    int tVotes[], int noOfRows)
{
    int i, j;
    int largestVotes = 0;
    int winLoc = 0;
    int sumVotes = 0;

    for(i = 0; i < noOfRows; i++)
    {
        if(largestVotes < tVotes[i])
        {
            largestVotes = tVotes[i];
            winLoc = i;
        } // end if

        sumVotes = sumVotes + tVotes[i];

        cout << left;
        cout << setw(9) << cNames[i] << "  ";
        cout << right;
        for(j = 0; j < NO_OF_REGIONS; j++)
            cout << setw(8) << vbRegion[i][j] << "  ";
        cout << setw(6) << tVotes[i] << endl;
    } // end for

    cout << endl << endl << "Winner: " << cNames[winLoc]
         << ", Votes Received: " << tVotes[winLoc]
         << endl << endl;
    cout << "Total votes polled: " << sumVotes << endl;
} // end function printResult
