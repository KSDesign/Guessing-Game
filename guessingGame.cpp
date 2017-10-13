//guessingGame.cpp
//Sakhrani:Kabir:A00376745:csc34141
//Submission 06: Guessing A Secret Code with a Game Class

/*
The entire program works.
*/

#include <iostream> //this is where cout, endl and cin.ignore() live
#include <string> //this is where getline() and to_string() live

using namespace std; //<- This is a "using directive"

#include "Game.h"
#include "utilities.h"
using Scobey::DisplayOpeningScreen;
using Scobey::Pause;
using Scobey::TextItems;
using Scobey::Menu;
using Scobey::RandomGenerator;

extern const string MY_ID_INFO = "Sakhrani:Kabir:A00376745:CSC34141";

void Game::getSecretCode()
{
    string decision;
    cout << "Would you like to enter your own \"secret\" code? (y/[n]) ";
    cin >> decision;
    //User input the secret code and secret code is validated
    if (decision == "y" || decision == "Y")
    {
        cout << "OK. Enter the code here: ";
        cin >> secretCode;
        if (secretCodeIsValid() == true)
        {
            goto done;
        }
    }
    //Random secret code is generated
    else
    {
        RandomGenerator randGen;
        secretCode = randGen.getNextString("xxxx....13578642");
        cout << "\nOK. A random secret code has been generated.\n";
    }
    done:;
    //Clears input stream
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool Game::secretCodeIsValid()
{
    //Initializing varibale
    int counterB = 0;
    bool yesOrNoError = true;

    for (int x = 0; x <= secretCode.length() - 1; x++)
    {
        //Variable to store character for secretCode at each iteration
        //Converts character to an int at the same time
        int codeDigits = (secretCode.at(x) - '0');

        // Checks if each character is within the range
        if ((codeDigits > 8) || (codeDigits < 1))
        {
            counterB += 1;
        }
    }

    //Output if only secretCode has a digit/digits not in range
    if (counterB >= 1)
    {
        yesOrNoError = false;
    }
    //Output if only secretCode is not 4 characters long
    else if (secretCode.length() != 4)
    {
        yesOrNoError = false;
    }
    return yesOrNoError;
}

void Game::play()
{
    string firstGuess;
    string guessAgain;
    cout << "\nSecret code is ****                   First guess? ";
    cin >> firstGuess;
    for (guessCount = 1; guessCount <= 10; guessCount++)
    {
        //Output for when guessCount equal to 1
        if (guessCount == 1)
        {
            cout << "\nGuess  #" << guessCount << " is " << firstGuess
                << "   Score is " << score(firstGuess, secretCode);
            if (score(firstGuess, secretCode).compare("40") == 0)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            //Prompts user for next guess
            else
            {
                cout << "        Next guess? ";
                cin >> guessAgain;
            }
        }
        //Ouput for when guessCount is between 2 and 9
        else if (guessCount >= 2 && guessCount <= 10)
        {
            if (guessCount >= 2 && guessCount <= 9)
            {
                cout << "Guess  #" << guessCount << " is " << guessAgain
                     << "   Score is " << score(guessAgain, secretCode);
            }
            if (guessCount == 10)
            {
                cout << "Guess #" << guessCount << " is " << guessAgain
                     << "   Score is " << score(guessAgain, secretCode);
            }
            if (score(guessAgain, secretCode).compare("40") == 0)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            //Prompts user for next guess
            else
            {
                if (guessCount != 10)
                {
                    cout << "        Next guess? ";
                    cin >> guessAgain;
                }
            }
        }
    }
}

void Game::reportResult()
{
    if (finalScore.compare("40") == 0)
    {
        //Output for when guessCount equal to 1
        if (guessCount == 1)
        {
            cout << "\n\nCongratulations! Victory in " << guessCount
                << " guess.\n";
        }
        //Ouput for when guessCount is between 2 and 9
        else if (guessCount >= 2 && guessCount <= 10)
        {
            cout << "\n\nCongratulations! Victory in " << guessCount
                << " guesses.\n";
        }
    }
    else
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n\nSorry, you've used up all 10 of your guesses.\n"
            "Here is the secret code: " << secretCode << "\n";
    }
}

string Game::score
(
const string& code1, //in
const string& code2  //in
)
{
    //Declares/Initializes variables
    int charPosition;
    int b;
    int firstDigit = 0;
    int secondDigitA = 0;
    int secondDigitB = 0;
    int secondDigitC = 0;
    int secondDigitD = 0;

    //Checks if digit at same character position are equal for code1 and code2
    for (charPosition = 0; charPosition <= 3; charPosition++)
    {
        if (code1.at(charPosition) == code2.at(charPosition))
        {
            firstDigit += 1;
        }
    }

    //Loops to check if there are partial matches between code1 and code2
    for (b = 0; b <= 3; b++)
    {
        if (b != 0)
        {
            if (code1.at(0) == code2.at(b) && code1.at(0) != code2.at(0))
            {
                if (code1.at(b) != code2.at(b))
                {
                    secondDigitA = 1;
                }
            }
        }
    }
    for (b = 0; b <= 3; b++)
    {
        if (b != 1)
        {
            if (code1.at(1) == code2.at(b) && code1.at(1) != code2.at(1))
            {
                if (code1.at(0) != code2.at(b))
                {
                    secondDigitB = 1;
                }
            }
        }
    }
    for (b = 0; b <= 3; b++)
    {
        if (b != 2)
        {
            if (code1.at(2) == code2.at(b) && code1.at(2) != code2.at(2))
            {
                if (code1.at(0) != code2.at(b))
                {
                    secondDigitC = 1;
                }
                else if (code1.at(1) != code2.at(b))
                {
                    secondDigitC = 1;
                }
            }
        }
    }
    for (b = 0; b <= 3; b++)
    {
        if (b != 3)
        {
            if (code1.at(3) == code2.at(b) && code1.at(3) != code2.at(3))
            {
                if (code1.at(0) != code2.at(b))
                {
                    secondDigitD = 1;
                }
                else if (code1.at(1) != code2.at(b))
                {
                    secondDigitD = 1;
                }
                else if (code1.at(2) != code2.at(b))
                {
                    secondDigitD = 1;
                }
            }
        }
    }

    //Calculates value for the second digit
    int totalSecondDigit = secondDigitA + secondDigitB + secondDigitC
        + secondDigitD;
    string stringFirstDigit = to_string(firstDigit);
    string stringSecondDigit = to_string(totalSecondDigit);
    //Calculates value for finalScore
    finalScore = stringFirstDigit + stringSecondDigit;
    return finalScore;
}
