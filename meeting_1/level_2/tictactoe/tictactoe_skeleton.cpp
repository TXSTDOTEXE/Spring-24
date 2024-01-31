#include <iostream>
using namespace std;

/*
    This sample code is provided to help develop a Tic-Tac-Toe program faster or with limited
    knowledge with classes. The only thing to implement is the game logic in main. If you have
    any questions feel free to use the internet or ask for help. 
*/

// This class will store our game board and functions for making moves
class Board{
    private:
        char board[3][3] = {
               {'-','-','-'},
               {'-','-','-'},
               {'-','-','-'}
            }; // the board is a 3x3 grid
    public:
        void displayBoard(){
            for(int r = 0; r < 3; r++){
                for(int c = 0; c < 3; c++){
                    cout << board[r][c] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

        // Returns if the move is valid
        bool playerMove(int player, int row, int col){
            if(board[row][col] != '-')
                return false;
            board[row][col] = (player == 1) ? 'X' : 'O'; // if player is 1, put X, Y otherwise.
            return true;
        }
        // Returns true if inserted player is the winner
        bool checkWin(int player){
            char chToCheck = (player == 1) ? 'X' : 'O';
            // Check rows
            for(int row = 0; row < 3; row++){
                bool allSame = true;
                for(int col = 0; allSame && col < 3; col++){
                    if(board[row][col] != chToCheck){
                        allSame = false;
                    }
                }
                if(allSame)
                    return true;
            }

            //Check cols
            for(int col = 0; col < 3; col++){
                bool allSame = true;
                for(int row = 0; row < 3; row++){
                    if(board[row][col] != chToCheck)
                        allSame = false;
                }
                if(allSame)
                    return true;
            }
            //Check diag
            bool allSame = true;
            for(int i = 0; i < 3; i++){
                if(board[i][i] != chToCheck)
                    allSame = false;
            }
            if(allSame) return true;

            if(board[2][0] == chToCheck && board[1][1] == chToCheck && board[0][2] == chToCheck)
                return true;
            return false;
        }

};

int main(){
    Board board; // Board object, use to call the functions in the class.
    // You can place a X or O on the board by calling board.playerMove(player # (1 or 2), row, column)
    // EXAMPLE: Playing a X at row 2, column 0 would be board.playerMove(1,2,0);

    // INSERT GAME LOGIC HERE!
    /*
        Challenges if this is too easy for you:
            - Make the program play as player 2
                (could be random or if you want to go all out, make it have a strategy)
            - Make the game board bigger, try 5x5 or 10x10
                Hint: You will need to modify the code in the class
    */
    return 0;
}