/*
    Description: A TicTacToe game that is written in a class that can control the game.
    Autho: Harrison Chen
*/

#include <iostream>
using namespace std;

/*
     A class for the game board TicTacToe
*/
class TicTacToe {
    private:
        char ** board;
        bool endGameLoop;
        bool endTurnLoop;
        int turnCounter;
        bool playerCounter;
    public:
        TicTacToe();
        ~TicTacToe();
        void print();
        void init();
        void updateP1(int, int);
        void updateP2(int, int);
        void switchPlayer();
        bool checkEndGame() {return endGameLoop;};
        bool checkEndTurn() {return endTurnLoop;};
        void checkWhoWin();
        bool checkPlayer() {return playerCounter;};
        void setTurnCounter(int);
        int getTurnCounter() {return turnCounter;};
        void setEndGameLoop(bool);
};

/*
    Constructor for the game board
*/
TicTacToe::TicTacToe(){
    endGameLoop = false;
    endTurnLoop = false;
    turnCounter = 1;
    playerCounter = true;
    init();
}

/*
    Deconstructor for the game board
*/
TicTacToe::~TicTacToe(){
    delete board;
}

/*
    A void function that prints the board
*/
void TicTacToe::print(){
    cout << " |0|1|2|\n";
        for(int row = 0; row < 3; row++){
            cout << "--------\n";
            cout << row <<"|";
            for(int col = 0; col < 3; col++){
                cout << *(*(board + row) + col) << "|";
            }
            cout << "\n";
        }
}

/*
    A void function that initilized the game board
*/
void TicTacToe::init(){
    board = new char * [3];
    for(int i = 0; i < 3; i++){
        board[i] = new char[3];
    }
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            *(*(board + row) + col) = '*';
        }
    }
}

/*
    A void function that sets the status of the endGameLoop
    @param status, boolean vaule that decide to end the game or not
*/
void TicTacToe::setEndGameLoop(bool status){
    endGameLoop = status;
}

/*
    A void function that sets the turnCounter
    @param amount, int vaule that increase the value of turns by the amount of number
*/
void TicTacToe::setTurnCounter(int amount){
    turnCounter += amount;
}

/*
    A void function that switch the playerConter to true(P1) or false(P2);
*/
void TicTacToe::switchPlayer(){
    playerCounter = !playerCounter;
}

/*
    A void function that updates the board based up player 1's input
    @param row, user input row
    @param col, user input col
*/
void TicTacToe::updateP1(int row, int col){
    if(row >= 0 && row <= 2 && col >= 0 && col <= 2){
        if(*(*(board + row) + col) == '*'){
            *(*(board + row) + col) = 'O';
            endTurnLoop = true;
        }else{
            cout << "\nThe block is already occupied, please try again.\n";
        }
    }else{
        cout << "\nInput is not valid, please try again.\n";
    }
}

/*
    A void function that updates the board based up player 2's input
    @param row, user input row
    @param col, user input col
*/
void TicTacToe::updateP2(int row, int col){
    if(row >= 0 && row <= 2 && col >= 0 && col <= 2){
        if(*(*(board + row) + col) == '*'){
            *(*(board + row) + col) = 'X';
            endTurnLoop = true;
        }else{
            cout << "\nThe block is already occupied, please try again.\n";
        }
    }else{
        cout << "\nInput is not valid, please try again.\n";
    }
}

/*
    A void function that checks who won the game
*/
void TicTacToe::checkWhoWin(){
    if( (*(*(board)) == 'O' && *(*(board)+1) == 'O' && *(*(board)+2) == 'O') 
        ||  (*(*(board+1)) == 'O' && *(*(board+1)+1) == 'O' && *(*(board+1)+2) == 'O') 
        ||  (*(*(board+2)) == 'O' && *(*(board+2)+1) == 'O' && *(*(board+2)+2) == 'O')
        ||  (*(*(board)) == 'O' && *(*(board+1)) == 'O' && *(*(board+2)) == 'O') 
        ||  (*(*(board)+1) == 'O' && *(*(board+1)+1) == 'O' && *(*(board+2)+1) == 'O')
        ||  (*(*(board)+2) == 'O' && *(*(board+1)+2) == 'O' && *(*(board+2)+2) == 'O')
        ||  (*(*(board)) == 'O' && *(*(board+1)+1) == 'O' && *(*(board+2)+2) == 'O')
        ||  (*(*(board)+2) == 'O' && *(*(board+1)+1) == 'O' && *(*(board+2)) == 'O')){
            for(int row = 0; row < 3; row++){
                cout << "--------\n";
                cout << row <<"|";
                for(int col = 0; col < 3; col++){
                    cout << *(*(board + row) + col) << "|";
                }
                cout << "\n";
            }
            cout << "\nPlayer One Won!!\n";
            endGameLoop = true;
        }
        // Check for player two win
        if( (*(*(board)) == 'X' && *(*(board)+1) == 'X' && *(*(board)+2) == 'X') 
        ||  (*(*(board+1)) == 'X' && *(*(board+1)+1) == 'X' && *(*(board+1)+2) == 'X') 
        ||  (*(*(board+2)) == 'X' && *(*(board+2)+1) == 'X' && *(*(board+2)+2) == 'X')
        ||  (*(*(board)) == 'X' && *(*(board+1)) == 'X' && *(*(board+2)) == 'X') 
        ||  (*(*(board)+1) == 'X' && *(*(board+1)+1) == 'X' && *(*(board+2)+1) == 'X')
        ||  (*(*(board)+2) == 'X' && *(*(board+1)+2) == 'X' && *(*(board+2)+2) == 'X')
        ||  (*(*(board)) == 'X' && *(*(board+1)+1) == 'X' && *(*(board+2)+2) == 'X')
        ||  (*(*(board)+2) == 'X' && *(*(board+1)+1) == 'X' && *(*(board+2)) == 'X')){
            cout << " |0|1|2|\n";
            for(int row = 0; row < 3; row++){
                cout << "--------\n";
                cout << row <<"|";
                for(int col = 0; col < 3; col++){
                    cout << *(*(board + row) + col) << "|";
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

// TicTacToe Demo
int main(){
    int inputRow;   //user input row
    int inputCol;   //user input col

    // Create board
    TicTacToe *board = new TicTacToe();
    // Game start
    while(!board->checkEndGame()){
        board->print();
        // Check for player turn
        if(board->checkPlayer()){
            //Player 1 turn
            while(!board->checkEndTurn()){
                cout << "Player One's Turn (O):\n";
                cout << "Please enter the row and column you want to place your symbol: ";
                cin >> inputRow >> inputCol;
                board->updateP1(inputRow, inputCol);
                cin.clear();
            }
            // Switch to player 2
            board->switchPlayer();
        }else{
            //Player 2 turn
            while(!board->checkEndTurn()){
                cout << "Player Two's Turn (X):\n";
                cout << "Please enter the row and column you want to place your symbol: ";
                cin >> inputRow >> inputCol;
                board->updateP2(inputRow, inputCol);
                cin.clear();
            }
            // Switch to player 1
            board->switchPlayer();
        }
        cin.clear();
        cin.ignore();
        // Check who win
        board->checkWhoWin();
    }
    return 0;
}
