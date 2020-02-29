/*
    Author: Harrison Chen
    Project number: 1
    Description: A program that asks the user to enter an odd integer between 1 and 15 (both inclusive). 
    If the integer value was 3, then print out the following diamond pattern on screen.     
*/
#include <iostream>
using namespace std;

int main(){
    int userNum;
    bool endLoop = false;
    cout << "Please enter an odd integer number between 1 and 15: ";
    while(!endLoop){
        cin >> userNum;
        if(userNum > 0 && userNum < 15 && userNum % 2 == 1){
            for(int i = 1; i <= userNum; i += 2){
                for(int j = (userNum - i)/2; j > 0; j--){
                    cout << " ";
                }
                for(int k = i; k >= 1; k--){
                    cout << "*";
                }
                for(int m = (userNum -i)/ 2; m >= 0; m--){
                    cout << " ";
                }
                cout << "\n";
            }
            for(int i = userNum-2; i >= 1; i -= 2){
                for(int j = (userNum - i) / 2; j > 0; j--){
                    cout << " ";
                }
                for(int k = i; k >= 1; k--){
                    cout << "*";
                }
                for(int m = (userNum -i)/ 2; m >= 0; m--){
                    cout << " ";
                }
                cout << "\n";
            }
            return 0;
        }
        else{
            cout << "Invalid Input. Please enter an odd integer number between 1 and 15: ";
        }
    }
}