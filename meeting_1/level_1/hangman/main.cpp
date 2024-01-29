/* This program provides a partial solution for a hangman game.
   The core mechanic of the game works; however,  
   consider adding implentation to flesh out the full project.
   
   Some ideas are:
   Consider input validation for single-letter input and preventing 
   letter repetition. 
   Making ascii art for the hangman instead of blanks.
   etc..
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Select a random word from the array
string getRandomWord() {
    string words[] = {"programming", "exe", "texas", "welcome", "hello"};
    srand(time(0));
    int randomIndex = rand() % 5;
    return words[randomIndex];
}

// Displays the screen with underscores given the length of the word
string initializeDisplay(int length) {
    return string(length, '_');
}

// Checks if the user's guess is in the random word
bool updateDisplay(string& display, const string& word, char guess) {
    bool found = false;
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == guess) {
            display[i] = guess;
            found = true;
        }
    }
    return found;
}

int main() {

   string selectedWord = getRandomWord();
   int length = selectedWord.length();
   string display = initializeDisplay(length);
   int attempts = 6;

   while (attempts > 0) {
        cout << "Current word: " << display << endl;
        cout << "Attempts left: " << attempts << endl;

        char guess;
        cout << "Enter a letter: ";
        cin >> guess;

        if (!updateDisplay(display, selectedWord, guess)) {
            --attempts;
            cout << "Incorrect guess. Try again." << endl;
        }

        if (display == selectedWord) {
            cout << "Congratulations! You guessed the word: " << selectedWord << endl;
            return 0;
        }
        
   }

   cout << "Try again next time! The correct word was: " << selectedWord << endl;

   return 0;
}
