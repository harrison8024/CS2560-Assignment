/*
    Author: Harrison Chen
    Project number: 1
    Description: ATM simulator that has a saving account and a checking account. 
    It can also transfer or withdraw money from either account, and check the amount as well.

    ***NOTE: If user is using windows system, needs to change 'system("clear")' to 'system("cls")'***
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

void withdrawMenu(float &, float &);
void displayBalance(float, char);

int main(){
    int passwordCounter = 0;
    float amount = 0;
    float savingBalance = 1000;
    float checkingBalance = 1000;
    int inputPassword, userOption;
    bool endPasswordLoop = false;
    bool endOptionsLoop = false;
    cout << "*** Welcom to Cal Poly's ATM ***\n\n";
    while(passwordCounter < 3 && !endPasswordLoop){
        cout << "Please enter your PIN: "; 
        cin >> inputPassword;
        if(inputPassword == 111){
            endPasswordLoop = true;
        }
        passwordCounter++;
        //clear screen
        system("clear");
    }

    // Terminate Program if PIN is invalid 3 consecutive times
    if(passwordCounter >= 3){
        cout << "Too many illegal PINs. Try again later.\n";
        exit(1);
    }

    // Succesful login
    while(!endOptionsLoop){
        cout << "*** Welcom To Cal Poly's ATM System ***\n\n";
        cout << "(1) Transfer from checking account to savings account\n\n";
        cout << "(2) Transfer from savings account to checking account\n\n";
        cout << "(3) Savings account balance\n\n";
        cout << "(4) Checking account balance\n\n";
        cout << "(5) Withdraw Cash from either account\n\n";
        cout << "(6) Exit\n\n";
        cout << "==> Please select option(1-6): ";
        cin >> userOption;
        switch(userOption){
            case 1:
                system("clear");
                cout << "Amount you would like to transfer from checking account to savings account: $";
                cin >> amount;
                amount = floor(100*amount) / 100;
                while(amount > checkingBalance){
                    displayBalance(checkingBalance, 'c');
                    cout << "Insufficient fund, enter 0 to cancel please enter a new amount: $";
                    cin >> amount;
                    amount = floor(100*amount) / 100;
                    cin.clear();
                }
                checkingBalance -= amount;
                savingBalance += amount;
                if(amount == 0){
                    cout << "Transaction canceled.\n";
                }
                else{
                    cout << "Transaction completed.\n";
                }
                break;
            case 2:
                system("clear");
                cout << "Amount you would like to transfer from savings account to checking account: $";
                cin >> amount;
                amount = floor(100*amount) / 100;
                while(amount > savingBalance){
                    displayBalance(savingBalance, 's');
                    cout << "Insufficient fund, enter 0 to cancel or enter a new amount: $";
                    cin >> amount;
                    amount = floor(100*amount) / 100;
                    cin.clear();
                }
                checkingBalance += amount;
                savingBalance -= amount;
                if(amount == 0){
                    cout << "Transaction canceled.\n";
                }
                else{
                    cout << "Transaction completed.\n";
                }
                break;
            case 3:
                system("clear");
                displayBalance(savingBalance, 's');
                break;
            case 4:
                system("clear");
                displayBalance(checkingBalance, 'c');
                break;
            case 5:
                system("clear");
                withdrawMenu(savingBalance, checkingBalance);
                break;
            case 6:
                system("clear");
                endOptionsLoop = true;
                break;
            default:
                endOptionsLoop = false;
                break;
        }
        cin.clear();
        cin.ignore();
    }
    cout << "Thank you for using the ATM system." << endl;
    exit(0); 
}

void withdrawMenu(float &savingBalance, float &checkingBalance){
    int withdrawOption, withdrawAmount;
    bool endWithdrawLoop = false;
    while(!endWithdrawLoop){
        cout << "(1) Savings Account\n";
        cout << "(2) Checking Account\n";
        cout << "(3) Back to main menu\n";
        cout << "Which account would you like to withdraw from: ";
        cin >> withdrawOption;
        switch(withdrawOption){
            case 1: 
                displayBalance(savingBalance, 's');
                cout << "\nPlease enter amount you desired to withdraw: $";
                cin >> withdrawAmount; 
                while(withdrawAmount > savingBalance){
                    cout << "\nInsufficient fund, enter 0 to cancel or enter a new amount: $";
                    cin >> withdrawAmount;
                    withdrawAmount = floor(100*withdrawAmount) / 100;
                    cin.clear();
                }
                savingBalance -= withdrawAmount;
                if(withdrawAmount == 0){
                    cout << "\nbTransaction canceled.\n";
                }
                else{
                    cout << "\nTransaction completed.\n";
                }
                break;
            case 2:
                displayBalance(checkingBalance, 'c');
                cout << "Please enter amount you desired to withdraw: $";
                cin >> withdrawAmount; 
                while(withdrawAmount > checkingBalance){
                    cout << "\nInsufficient fund, enter 0 to cancel or enter a new amount: $";
                    cin >> withdrawAmount;
                    withdrawAmount = floor(100*withdrawAmount) / 100;
                    cin.clear();
                }
                checkingBalance -= withdrawAmount;
                if(withdrawAmount == 0){
                    cout << "\nTransaction canceled.\n";
                }
                else{
                    cout << "\nTransaction completed.\n";
                }
                break;
            case 3:
                endWithdrawLoop = true;
                break;
            default:
                endWithdrawLoop = false;
                break;
        }
        cin.clear();
        cin.ignore();
    }
}

void displayBalance(float balance, char account){
    switch(account){
        case 'c':
            cout << fixed << setprecision(2); 
            cout << "\n------------------------------------\n";
            cout << "\nChecking accout balance: $" << setw(10) << balance<< "\n";
            cout << "\n------------------------------------\n\n";
            break;
        case 's':
            cout << fixed << setprecision(2);  
            cout << "\n------------------------------------\n";
            cout << "\nSaving accout balance: $" << setw(10) << balance << "\n";
            cout << "\n------------------------------------\n\n";
            break;
    }
}