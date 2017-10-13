//Game.h
//Submission 06: Guessing a Secret Code with a Game Class

#ifndef GAME_H
#define GAME_H

class Game
{
public:

    void getSecretCode();
    /**<
    Gets a code to be used as the secret code, either from the user
    at the keyboard, or randomly generated.
    @post This Game object now contains a secret code, either obtained
    from the user, or randomly generated.
    */

    bool secretCodeIsValid();
    /**<
    Checks whether the secret code in this Game object is valid.
    @return The value true if the code is valid; otherwise, false.
    @pre This Game object contains a secret code.
    @post The value true has been returned if the secret code is valid;
    otherwise, the value false has been returned.
    */

    void play();
    /**<
    Handles the interaction with the user as the user makes a series of
    guesses to determine what the computer's secret code is.
    @pre The secret code of this Game object has been initialized with a
    valid code.
    @post The Game object contains the necessary information to enable
    reportResult() to be called (that is, the number of guesses that
    have been made, and the final score).
    */

    void reportResult();
    /**</
    Reports the end result of the user's sequence of guesses.
    @pre A call to play() has terminated.
    @post
    - If the user has guessed the secret code, one of the following
    messages will have been displayed (?? is a value in the range 2..10):
    <pre>
    Congratulations! Victory in 1 guess.
    Congratulations! Victory in ?? guesses.
    </pre>
    - If the user fails to guess the secret code in ten attempts, the following
    message will have been displayed (???? represents the secret code):
    <pre>
    Sorry, you've used up all 10 of your guesses."
    Here is the secret code: ????
    </pre>
    */

private:
    string secretCode;
    int guessCount;
    string finalScore;
    //Note that the score() function has become a private "helper function"
    //because it is only called by the member function play(), not by any
    //client of the class:
    string score
        (
        const string& code1, //in
        const string& code2  //in
        );
    /**<
    Computes and returns the score when two codes are compared.
    @return The two-digit score as a string object.
    @param code1 The first code.
    @param code2 The second code.
    @pre code1 and code2 have been initialize with valid codes.
    @post The score for the two codes has been returned.
    */
};

#endif
