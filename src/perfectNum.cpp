/*
    Author: Harrison Chen
    Project number: 2
    Description: The program ask for a positive integer number between 1 and 100,000. It will print all the perfect number between 1 and n
*/
#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int);

int main(){
    int inputNum, perfectNum, lastNum = 1, sum = 1, count = 1;
    bool endInputLoop = false, endPrintLoop = false;
    ofstream outFile;
    // User input validation
    while(!endInputLoop){
        cout << "Please enter an integer number between 1 and 100,000: ";
        cin >> inputNum;
        if(inputNum < 1 || inputNum > 100000){
            cout << "\nThe number you enter is invalid!\n";
        }else{
            endInputLoop = true;
        }
    }
    // Print perfect numbers
    outFile.open("perfectNumber.txt");
    while(!endPrintLoop){
        lastNum *= 2;
        sum += lastNum;
        count++;
        if(isPrime(sum)){
            perfectNum = lastNum * sum;
            if(perfectNum < inputNum){
                cout << perfectNum << " = 1";
                outFile << perfectNum << " = 1";
                for(int i  = 2; i <= perfectNum/2; i ++){
                    if(perfectNum % i == 0){
                        cout << " + " << i;
                        outFile << " + " << i;
                    }
                }
                cout << "\n";
                outFile << "\n";
            }else{
                endPrintLoop = true;
            }
        }
    }
    outFile.close();
}

bool isPrime(int num){
    for(int i = 2; i <= num/2; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}