/*
    Author: Harrison Chen
    Project number: 2
    Description: ATM simulator (written in functions) that has a saving account and a checking account. 
    It can also transfer or withdraw money from either account, and check the amount as well.

    ***NOTE: If user is using windows system, needs to change 'system("clear")' to 'system("cls")'***
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

void displayMenu();
void withdrawMenu(float &, float &);
void displayBalance(float, char);
void transferBalance(float &, float &, char);
void withdrawCash(float &);

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
        displayMenu();
        cin >> userOption;
        switch(userOption){
            case 1:
                system("clear");
                transferBalance(checkingBalance, savingBalance, 'c');
                break;
            case 2:
                system("clear");
                transferBalance(savingBalance, checkingBalance, 's');
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

void displayMenu(){
    cout << "*** Welcom To Cal Poly's ATM System ***\n\n";
        cout << "(1) Transfer from checking account to savings account\n\n";
        cout << "(2) Transfer from savings account to checking account\n\n";
        cout << "(3) Savings account balance\n\n";
        cout << "(4) Checking account balance\n\n";
        cout << "(5) Withdraw Cash from either account\n\n";
        cout << "(6) Exit\n\n";
        cout << "==> Please select option(1-6): ";
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
                withdrawCash(savingBalance);
                break;
            case 2:
                displayBalance(checkingBalance, 'c');
                withdrawCash(checkingBalance);
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

void transferBalance(float &fromBalance, float &toBalance, char transferOption){
    float amount;
    switch(transferOption){
        case 'c':
            cout << "Amount you would like to transfer from checking account to savings account: $";
            break;
        case 's':
            cout << "Amount you would like to transfer from savings account to checking account: $";
            break;
        break;
    }
    cin >> amount;
    amount = floor(100*amount) / 100;
    while(amount > fromBalance){
        displayBalance(fromBalance, transferOption);
        cout << "Insufficient fund, enter 0 to cancel or enter a new amount: $";
        cin >> amount;
        amount = floor(100*amount) / 100;
        cin.clear();
    }
    fromBalance -= amount;
    toBalance += amount;
    if(amount == 0){
        cout << "Transaction canceled.\n";
    }
    else{
        cout << "Transaction completed.\n";
    }
}

void withdrawCash(float &balance){
    float withdrawAmount;
    cout << "Please enter amount you desired to withdraw: $";
    cin >> withdrawAmount; 
    while(withdrawAmount > balance){
        cout << "\nInsufficient fund, enter 0 to cancel or enter a new amount: $";
        cin >> withdrawAmount;
        withdrawAmount = floor(100*withdrawAmount) / 100;
        cin.clear();
    }
    balance -= withdrawAmount;
    if(withdrawAmount == 0){
        cout << "\nTransaction canceled.\n";
    }
    else{
        cout << "\nTransaction completed.\n";
    }
}