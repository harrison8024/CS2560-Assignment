/*
    Author: Harrison Chen
    Project number: 2
    Description: This is a game called tic-tac-toe, two player places X or O on a 3x3 board until a player has a line of 3 X or O then the player wins.
*/
#include <iostream>
using namespace std;

int main(){
    char board[3][3];
    bool endGameLoop = false, endTurnLoop = false;
    int inputRow, inputCol, turnCounter = 1;
    bool playerCounter = true;
    // Initialize game board
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            board[row][col] = '*';
        }
    }
    // Game start
    while(!endGameLoop){
        cout << " |0|1|2|\n";
        for(int row = 0; row < 3; row++){
            cout << "--------\n";
            cout << row <<"|";
            for(int col = 0; col < 3; col++){
                cout << board[row][col] << "|";
            }
            cout << "\n";
        }
        // Check for player turn
        if(playerCounter){
            //Player 1 turn
            while(!endTurnLoop){
                cout << "Player One's Turn (O):\n";
                cout << "Please enter the row and column you want to place your symbol: ";
                cin >> inputRow >> inputCol;
                if(inputRow >= 0 && inputRow <= 2 && inputCol >= 0 && inputCol <= 2){
                    if(board[inputRow][inputCol] == '*'){
                        board[inputRow][inputCol] = 'O';
                        endTurnLoop = true;
                    }else{
                        cout << "\nThe block is already occupied, please try again.\n";
                    }
                }else{
                    cout << "\nInput is not valid, please try again.\n";
                }
                cin.clear();
            }
            // Switch to player 2
            board->switchPlayer();
        }else{
            //Player 2 turn
            while(!endTurnLoop){
                cout << "Player Two's Turn (X):\n";
                cout << "Please enter the row and column you want to place your symbol: ";
                cin >> inputRow >> inputCol;
                if(inputRow >= 0 && inputRow <= 2 && inputCol >= 0 && inputCol <= 2){
                    if(board[inputRow][inputCol] == '*'){
                        board[inputRow][inputCol] = 'X';
                        endTurnLoop = true;
                    }else{
                        cout << "\nThe block is already occupied, please try again.\n";
                    }
                }else{
                    cout << "\nInput is not valid, please try again.\n";
                }
                cin.clear();
            }
            // Switch to player 1
            playerCounter = true;
        }
        cin.clear();
        cin.ignore();
        // Check for player one win
        if( (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') 
        ||  (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') 
        ||  (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
        ||  (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') 
        ||  (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
        ||  (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
        ||  (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
        ||  (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')){
            for(int row = 0; row < 3; row++){
                cout << "--------\n";
                cout << row <<"|";
                for(int col = 0; col < 3; col++){
                    cout << board[row][col] << "|";
                }
                cout << "\n";
            }
            cout << "\nPlayer One Won!!\n";
            endGameLoop = true;
        }
        // Check for player two win
        if( (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') 
        ||  (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') 
        ||  (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
        ||  (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') 
        ||  (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
        ||  (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
        ||  (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
        ||  (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')){
            cout << " |0|1|2|\n";
            for(int row = 0; row < 3; row++){
                cout << "--------\n";
                cout << row <<"|";
                for(int col = 0; col < 3; col++){
                    cout << board[row][col] << "|";
                }
                cout << "\n";
            }
            cout << "\nPlayer Two Won!!\n";
            endGameLoop = true;
        }
        // Check if it is a draw
        if(turnCounter == 9){
            cout << "\nIt's a draw.\n";
            endGameLoop = true;
        }
        turnCounter++;
        endTurnLoop = false;
    }
}