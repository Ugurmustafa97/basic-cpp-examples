#include <iostream>

using namespace std;

enum objectType {ROCK, PAPER, SCISSORS};

void displayRules();

bool validSelection(char selection);

objectType retrievePlay(char selection);

void gameResult(objectType play1, objectType play2,
                int& winner);

void convertEnum(objectType object);

objectType winningObject(objectType play1, objectType play2);

void displayResults(int gCount, int wCount1, int wCount2);

int main()
{
        // Step 1 declare variables
    int gameCount;

    int winCount1;

    int winCount2;

    int gamewinner;
    char response;

    char selection1;
    char selection2;
    objectType play1;
    objectType play2;

        // Step 2 initialize variables
    gameCount = 0;
    winCount1 = 0;
    winCount2 = 0;

        // Step 3 Display
    displayRules();

        // Step 4 prompt user to play the game
    cout << "Enyet Y/y to play the game: ";
    cin >> response;
    cout << endl;
    while(response == 'Y' || response == 'y')
    {
        cout << "Player 1 enter your choice: ";
        cin >> selection1;
        cout << endl;

        cout << "Player 2 enter your choice: ";
        cin >> selection2;
        cout << endl;

        if(validSelection(selection1)
            && validSelection(selection2))
        {
            play1 = retrievePlay(selection1);
            play2 = retrievePlay(selection2);
            gameCount++;
            gameResult(play1, play2, gamewinner);

            if(gamewinner == 1)
                winCount1++;
            else if(gamewinner == 2)
                winCount2++;
        } // end if
        cout << "Enter Y/y to play the game: ";
        cin >> response;
        cout << endl;
    } // end while

    displayResults(gameCount, winCount1,
                    winCount2);

    return 0;
}

void displayRules()
{
    cout << " Welcome to the game of Rock, Paper, "
         << "and Scissors." << endl;
    cout << " player selects one of the objects Rock, "
         << "Paper, or Scissors." << endl;
} // end function displayRules

bool validSelection(char selection)
{
    switch(selection)
    {
        case 'R':
        case 'r':
        case 'P':
        case 'p':
        case 'S':
        case 's':
            return true;
        default:
            return false;
    } // end switch
} // end function validSelection

objectType retrievePlay(char selection)
{
    objectType object;

    switch(selection)
    {
    case 'R':
    case 'r':
        object = ROCK;
        break;
    case 'P':
    case 'p':
        object = PAPER;
        break;
    case 'S':
    case 's':
        object = SCISSORS;
    } // end switch

    return object;
} // end function retrievePlay

void gameResult(objectType play1, objectType play2,
                int& winner)
{
    objectType winnerObject;

    if(play1 == play2)
    {
        winner = 0;
        cout << "Both players selected ";
        convertEnum(play1);
        cout << ". This game is a tie." << endl;
    } //end if
    else
    {
        winnerObject = winningObject(play1,play2);
            // Output each player's choice
        cout << "Player 1 selected ";
        convertEnum(play1);
        cout << " and player 2 selected ";
        convertEnum(play2);
        cout << ". ";
            // Decide the winner
        if(play1 == winnerObject)
            winner = 1;
        else if(play2 == winnerObject)
            winner = 2;

            // Output the winner
        cout << "Player " << winner << " wins this game."
             << endl;

    } // end else
} // end function gameResult

void convertEnum(objectType object)
{
    switch(object)
    {
    case ROCK:
        cout << "Rock";
        break;
    case PAPER:
        cout << "Paper";
        break;
    case SCISSORS:
        cout << "Scissors";
    } // end switch
} // end function convertEnum

objectType winningObject(objectType play1, objectType play2)
{
    if((play1 == ROCK && play2 == SCISSORS)
        || (play2 == ROCK && play1 == SCISSORS))
            return ROCK;
    else if((play1 == SCISSORS && play2 == PAPER)
            || (play2 == SCISSORS && play1 == PAPER))
            return SCISSORS;
    else
        return SCISSORS;
} // end function winningObject

void displayResults(int gCount, int wCount1, int wCount2)
{
    cout << "The total number of plays: " << gCount
         << endl;
    cout << "The number of plays won by player 1: "
         << wCount1 << endl;
    cout << "The number of plays won by player 2: "
         << wCount2 << endl;
} // end function displayResults


