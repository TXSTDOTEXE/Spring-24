/* The objective of this mini project is to collaborate and learn. 
The provided code is a starting point, incomplete, and likely contains bugs. 
Your task is to fill in the missing code and implement the missing pieces
Feel free to modify the code extensively.
Don't be afraid to use the internet or ask for help.
Most importantly have fun!
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Create a function to select a random word from an array
string getRandomWord() {

   // Create an array with 5 words 
    

    srand(time(0)); // generates a random seed/number
    int randomIndex = rand() % 5;

    // return the word at randomIndex
}

// Displays the screen with underscores given the length of the word
string initializeDisplay(int length) {
    return string(length, '_');
}

// Checks if the user's guess is in the random word and updates the display
bool updateDisplay(string& display, const string& word, char guess) {
    
    /*For every word in the string, check if it matches the user's
    guess. Update display and other variables as needed.  
    */
   
   // return a boolean depending if the guess is in the word
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

        // Implement if the user's guess is correct 

        // Implement if the the user guessed the word  
   }

   cout << "Try again next time! The correct word was: " << selectedWord << endl;

   return 0;
}
