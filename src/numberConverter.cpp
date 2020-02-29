#include <iostream>
#include <string>
using namespace std;

int spaceNeeded(int, int);      // A function calculates the space needed for allocating stack 
string numConvert(int, int);    // A function that converts decimal to different base of number

// Main program
int main(){
    int option;                 // menu option
    bool endProgram = false;    // flag to end program while loop
    int number;                 // user input number
    char yesOrNo;               // user input char for program continuation

    //Program start
    cout << "------ Number Converter ------\n";
    while(!endProgram){
        // Prompt for a decimal number
        cout << "Enter a decimal number to convert: ";
        cin >> number;

        // Menu for number convertion
        cout << "1. Binary\n";
        cout << "2. Octal\n";
        cout << "3. Hexadecimal\n";
        cout << "4. Exit\n";
        cout << "Choose convertion or exit: ";
        cin >> option;

        // check user option
        switch(option){
            // Binary
            case 1:
                cout << "Decimal: " << number << "\n";
                cout << "Binary: " << numConvert(number, 2) << "\n";
                break;

            // Octal
            case 2:
                cout << "Decimal: " << number << "\n";
                cout << "Octal: " << numConvert(number, 8) << "\n";
                break;
            
            // Hexadecimal
            case 3:
                cout << "Decimal: " << number << "\n";
                cout << "Hexadecimal: " << numConvert(number, 16) << "\n";
                break;

            // Exit
            case 4:
                cout << "Exit Program.\n";
                endProgram = true;
                break;
        }

        // check to see if the program already ended
        if(!endProgram){

            // if program not ended, ask user if they would like to continue or not.
            cout << "Continue?(Y/N): ";
            cin >> yesOrNo;
            if(yesOrNo == 'Y' || yesOrNo == 'y'){
                endProgram = false;
            } else {
                cout << "Exit Program.\n";
                endProgram = true;
            }
        }
    }   
}

/**
* A function that converts decimal to different base of number
* @param num the decimal number being converted
* @param base the base number it is converting to
* @return a string that is the converted number
*/
string numConvert(int num, int base){
    int space = spaceNeeded(num, base); //get amount of space needed for stack
    int * stack = new int[space];       //allocating space for stack
    int count = 0; 
    string answer = "";

    //Number Convertion
    do{
        *stack = num % base;    // get quotient by base  and store remaining
        num /= base;            // devide by the base
        stack++;                // move stack to next position
        count++;                // increase count
    } while(num != 0);          // exit while loop when num is 0

    // Convert stack to string

    stack--;                    // move back one position to start at the last element of stack
    // Loop through the stack
    for(int *i = stack; i > stack - count; i--){
        // if number is less than 10, we use regular numbers
        if(*i < 10){
            answer += to_string(*i);    // concatenate the number to the answer string
        
        // else if number is equal or larger than 10 we use hexadecimal characters to represent number
        } else {
            char hex;
            switch(*i){
                case 10:
                    hex = 'A';
                    break;
                case 11:
                    hex = 'B';
                    break;
                case 12:
                    hex = 'C';
                    break;
                case 13:
                    hex = 'D';
                    break;
                case 14:
                    hex = 'E';
                    break;
                case 15:
                    hex = 'F';
                    break;
            }
            answer += hex;
        }
    }
    return answer;
}

/**
* A function calculates the space needed for allocating stack 
* @param num the decimal number being converted
* @param base the base number it is converting to
* @return a int that counts how many space is needed for stack
*/
int spaceNeeded(int num, int base){
    int count = 0;
    while(num != 0){
        num /= base;
        count++;
    }
    return count;
}