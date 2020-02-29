/*
    Author: Harrison Chen
    Project number: 1
    Description: This is a math tutor program, which helps student learn how to do addition, subtraction, multiplicationm and divisoin.
*/
#include <iostream>
using namespace std;
#include <stdlib.h> 
#include <time.h>
#include <iomanip>
#include <math.h>

int main(){
    // Use current time as seed for random generator
    srand(time(0));
    int inputOption, num1, num2, answer;
    bool endOptionLoop = false;
    while(!endOptionLoop){
        cout << "Welcom to Math Tutor!\n";
        cout << "(1) Addition problem\n";
        cout << "(2) Subtraction problem\n";
        cout << "(3) Multiplication problem\n";
        cout << "(4) Division problem\n";
        cout << "(5) Exit\n";
        cout << "=====> Please choose a problem to practice: ";
        cin >> inputOption;
        switch(inputOption){
            case 1:
                cout << "Solve this addition problem below:\n";
                num1 = rand()%999 + 1;
                num2 = rand()%999 + 1;
                cout << setw(4) << num1 << "\n";
                cout << "+" << setw(3) << num2 << "\n";
                cout << "____\n";
                cin >> answer;
                if(answer == num1 + num2){
                    cout << "\nCongradulations! Your answer is correct.\n";
                } else {
                    cout << "\nYour answer is incorrect. The correct answer is: " << (num1 + num2) << "\n\n"; 
                }
                break;
            case 2:
                cout << "Solve this subtraction problem below:\n";
                num1 = rand()%999 + 1;
                num2 = rand()%999 + 1;
                cout << setw(4) << num1 << "\n";
                cout << "-" << setw(3) << num2 << "\n";
                cout << "____\n";
                cin >> answer;
                if(answer == num1 - num2){
                    cout << "\nCongradulations! Your answer is correct.\n";
                } else {
                    cout << "\nYour answer is incorrect. The correct answer is: " << (num1 - num2) << "\n\n"; 
                }
                break;
            case 3:
                cout << "Solve this Multiplication problem below:\n";
                num1 = rand()%999 + 1;
                num2 = rand()%999 + 1;
                cout << setw(4) << num1 << "\n";
                cout << "x" << setw(3) << num2 << "\n";
                cout << "____\n";
                cin >> answer;
                if(answer == num1 * num2){
                    cout << "\nCongradulations! Your answer is correct.\n";
                } else {
                    cout << "\nYour answer is incorrect. The correct answer is: " << (num1 * num2) << "\n\n"; 
                }
                break;
            case 4:
                cout << "Solve this Division problem below: (Please only enter a whole number and leave the decimals)\n";
                num1 = rand()%999 + 1;
                num2 = rand()%999 + 1;
                cout << setw(4) << num1 << "\n";
                cout << "÷" << setw(3) << num2 << "\n";
                cout << "____\n";
                cin >> answer;
                if(answer == num1 / num2){
                    cout << "\nCongradulations! Your answer is correct.\n";
                } else {
                    cout << "\nYour answer is incorrect. The correct answer is: " << (num1 / num2) << "\n\n"; 
                }
                break;
            case 5:
                endOptionLoop = true;
                break;
            default:
                endOptionLoop = false;
                break;
        }
    }
    cout << "\n***Thank you for using Math Tutor!***\n";
    exit(0);
}