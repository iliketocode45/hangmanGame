#include <iostream>
#include <vector>

using namespace std;

//I used a function for generating a new word each time the user plays.
void RandomWordGenerator(vector<char> &word);

void StickMan(int& num);

int main() {
    //This first while loop and variable determine if the user wishes to play again.
    bool playAgain = true;
    while (playAgain) {
        //I created 3 vectors, 1 being the random word, 1 being what is printed and what is guessed by the user, and 1 for showing the incorrect guesses to the user.
        vector<char> word;
        vector<char> printedWord;
        vector<char> wrongGuesses;
        char userInput;
        bool endGame = false;
        bool wrongGuess = true;
        int loopCounter = 0;
        int wrongGuessCounter = 0;
        int guessCounter = 0;
        int stickManNum =0;

        //Word is randomly chosen.
        RandomWordGenerator(word);

        cout << "Welcome to the Game of Hangman!" << endl;
        cout << "A random word has been chosen. Enter the lowercase character of a letter to make a guess" << endl;
        cout << "Have fun!!" << endl;
        for (int i = 0; i < word.size(); i++) {
            //The dashed lines of the unguessed word are created for the user.
            printedWord.push_back('_');
        }
        //This while loop continues until the user has correctly guessed the word
        while (!endGame) {
            //User is told to guess and can see all the spaces left for guessing in word.
            cout << "Guess a letter:" << endl;
            for (int i = 0; i < word.size(); i++) {
                cout << printedWord.at(i) << " ";
            }
            cout << endl;
            //User makes a guess and guess goes through word to see if it is correct. If correct, it will be displayed in printWord. No character will be added to wrongGuesses and wrongGuess boolean will be false.
            cin >> userInput;
            for (int i = 0; i < word.size(); i++) {
                if (userInput == word.at(i)) {
                    printedWord.at(i) = userInput;
                    wrongGuess = false;
                }
            }
            //This for loop and following if statement help determine if the entire word has been guessed or not. It counts each character, and if all the characters are not the "_", the endGame is true and game ends.
            for (int i = 0; i < word.size(); i++) {
                if (printedWord.at(i) != '_') {
                    loopCounter = loopCounter + 1;
                }
                else {
                    loopCounter = loopCounter;
                }
            }
            if (loopCounter == word.size()) {
                endGame = true;
                break;
            }
            else {
                loopCounter = 0;
            }
            //If a wrong guess is made, this is displayed for the user.
            if (wrongGuess) {
                wrongGuessCounter = wrongGuessCounter + 1;
                wrongGuesses.push_back(userInput);
                cout << "Nope, try again" << endl;
                stickManNum = stickManNum + 1;
            }
            //If a correct guess is made, this is displayed for the user.
            else{
                cout << "Nice! You got one!" << endl;
            }
            //These following lines display the incorrect/correct/total guesses for the user and count the total guesses. wrongGuess is set to true in preparation for the user to make a guess again.
            cout << "These are your previous incorrect guesses:" << endl;
            for (int i = 0; i < wrongGuesses.size(); i++) {
                cout << wrongGuesses.at(i) << " ";
            }
            guessCounter = guessCounter + 1;
            cout << endl << "wrong guesses: " << wrongGuessCounter << " correct guesses: " << guessCounter - wrongGuessCounter << " total guesses: " << guessCounter << endl;
            wrongGuess = true;
            cout << "---" << endl << "  |" << endl;
            StickMan(stickManNum);
        }
        //When the user wins, this is displayed, showing how many guesses they made.
        cout << "Congrats! You won!!" << endl;
        for (int i = 0; i < word.size(); i++) {
            cout << printedWord.at(i) << " ";
        }
        cout << endl;
        cout << "You guessed the word correctly in: " << guessCounter << " guesses." << endl;
        //Poping the question if they would like to play again.
        cout << "Would you like to play the game again? (indicate with 'y' or 'n')" << endl;
        cin >> userInput;
        if (userInput != 'y') {
            playAgain = false;
        } else {
            playAgain = true;
        }
    }
    cout << "Thanks for playing!!" << endl;
    return 0;
}

void RandomWordGenerator(vector<char> &word) {
    //Function uses vectors for the word. It chooses a random number between 1 and 10 and picks of the 10 initializations for the vector.
    int randomInt;
    srand(time(0));
    randomInt = (rand() % 10) + 1;
    if (randomInt == 1) {
        word = {'s', 't', 'r', 'o', 'n', 'g'};
    } else if (randomInt == 2) {
        word = {'h', 'e', 'l', 'l', 'o'};
    } else if (randomInt == 3) {
        word = {'b', 'e', 'c', 'a', 'u', 's', 'e'};
    } else if (randomInt == 4) {
        word = {'c', 'a', 'r', 'e'};
    } else if (randomInt == 5) {
        word = {'b', 'o', 'o', 't'};
    } else if (randomInt == 6) {
        word = {'j', 'e', 'l', 'l', 'y'};
    } else if (randomInt == 7) {
        word = {'c', 'a', 'r'};
    } else if (randomInt == 8) {
        word = {'s', 'i', 'l', 'l', 'y'};
    } else if (randomInt == 9) {
        word = {'s', 'a', 'd', 'd', 'l', 'y'};
    } else if (randomInt == 10) {
        word = {'s', 'u', 'm'};
    }
}

void StickMan(int& num){
    if(num == 1) {
        cout << "  O" << endl;
    }
    else if(num == 2){
        cout << "  O" << endl << "  |" << endl;
    }
    else if(num == 3){
        cout << "  O" << endl << " /|" << endl;
    }
    else if(num == 4){
        cout << "  O" << endl << " /|\\" << endl;
    }
    else if(num == 5){
        cout << "  O" << endl << " /|\\" << endl << " /" << endl;
    }
    else {
        cout << "  O" << endl << " /|\\" << endl << " / \\" << endl << "Hang Man! but you can keep guessing if you'd like" << endl;
    }

}