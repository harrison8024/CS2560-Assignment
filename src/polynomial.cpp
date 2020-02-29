/*
    Description: A Polynomial class that can store its coefficient and exponent,
                and perform addition, subtraction, multiplication, and assignment.
    Autho: Harrison Chen
*/
#include <iostream>
#include <string>
using namespace std;

/**
    A class for Polynomial
*/
class Polynomial {
    private:
        int * coef;     // pointer to coefficient array
        int * expo;     // pointer to exponent array
        int largestExp; // the largest exponent
        string findCoef(string);
    public:
        Polynomial(int);
        Polynomial(int*, int*, int);    // constructor
        Polynomial(string, int);        // constructor for string input
        ~Polynomial();                  // deconstructor
        Polynomial(Polynomial *);       // copy constructor

        Polynomial operator+(Polynomial const &);   //Overload operator +
        Polynomial operator-(Polynomial const &);   //Overload operator -
        Polynomial operator=(Polynomial const &);   //Overload operator =
        Polynomial operator*(Polynomial const &);   //Overload operator *

        void setCoef(int*);
        void setExpo(int*);
        void initialize();

        int getLargestExp() const {return largestExp;};
        int* getCoef() const {return coef;};
        int* getExpo() const {return expo;};

        void print();
    
};

/*
    Constructor that takes a integer number
    @param largest, the largest number of exponent
*/
Polynomial::Polynomial(int largest){
    largestExp = largest;
    coef = new int[largest+1];
    expo = new int[largest+1];
    if(!coef || !expo){
        cout << "Allocation error.\n";
        exit(1);
    }
    initialize();
}

/*
    Constructor that takes two pointers and a integer
    @param co, array of coeficients
    @param ex, array of exponents
    @param largest, the largest number of exponent
*/
Polynomial::Polynomial(int* co, int* ex, int largest){
    largestExp = largest;
    coef = new int[largest+1];
    expo = new int[largest+1];
    if(!coef || !expo){
        cout << "Allocation error.\n";
        exit(1);
    }
    initialize();
    setCoef(co);
    setExpo(ex);
}

/*
    Constructor that takes a string and a integer number
    @param str, the string that holds the polynomial
    @param largest, the largest number of exponent
*/
Polynomial::Polynomial(string str, int largest){
    largestExp = largest;
    coef = new int[largest+1];
    expo = new int[largest+1];
    initialize();
    if(!coef || !expo){
        cout << "Allocation error.\n";
        exit(1);
    }
    int front = 0;              //Keeps the index of the begining of a number
    int back = 0;               //Index that goes thru the string
    int numberOf = 0;           //Number of number characters 
    bool isNegative = false;    //is the number negative

    // Checking each character in string
    while(back < str.length()){
        switch(str[back]){
            case ' ':
            {
                front++;
                back++;
                break;
            }
            case '-':
            {
                isNegative = true;
                front++;
                back++;
                break;
            }
            case '+':
            {
                isNegative = false;
                front++;
                back++;
                break;
            }
            case 'x':
            {
                int number;
                int expoPosition = str[back+2] - 48;
                string numberStr = str.substr(front, numberOf);
                if(numberStr == "x") {
                    number = 1;
                } else {
                    number = stoi(numberStr);
                }
                if(isNegative){
                    number = -number;
                }
                *(coef+expoPosition) = number;
                back += 4;
                front = back;
                break;
            }
            case '0': case '1': case '2': case '3': case '4': 
            case '5': case '6': case '7': case '8': case '9':
            {
                numberOf++;
                back++;
                break;
            }
            case '^':
            {
                back++;
                front++;
                break;
            }
            default:
            {
                cout << "Illegal character in polynomial.\n";
                exit(1); 
            }
        }
    }
}

/*
    Deconstructor
*/
Polynomial::~Polynomial(){
    delete coef;
    delete expo;
}

/*
    Copy Constructor
*/
Polynomial::Polynomial(Polynomial *ob){
    largestExp = ob->getLargestExp();
    coef = new int[largestExp+1];
    expo = new int[largestExp+1];
    if(!coef || !expo){
        cout << "Allocation error.\n";
        exit(1);
    }
    initialize();
    setCoef(ob->getCoef());
    setExpo(ob->getExpo());
}

/*
    A void Function that initilized the coeficient array and exponent array.
*/
void Polynomial::initialize(){
    for(int i = 0; i <= largestExp; i++){
        *(coef+i) = 0;
        *(expo+i) = i;
    }
}

/*
    A void function that sets the coeficient from the input array
    @param co, the input array of coeficient
*/
void Polynomial::setCoef(int* co){
    for(int i = 0; i <= largestExp; i++){
        *(coef+i) = *(co+i);
    }
}

/*
    A void function that sets the exponent from the input array
    @param ex, the input array of exponent
*/
void Polynomial::setExpo(int* ex){
    for(int i = 0; i <= largestExp; i++){
        *(expo+i) = *(ex+i);
    }
}

/*
    A void function prints out the polynomial to the screen
*/
void Polynomial::print(){
    int zeroCount = 0;
    for(int i = 0; i <= largestExp; i++){
        int co = *(coef+i);
        int ex = *(expo+i);
        if(co == 0){
            zeroCount++;
        }
        if(i && co != 0 && largestExp-zeroCount != 0){
            cout << " + ";
        }
        if(co != 0){
            cout << co << "x^" << ex;
        }
    }
    if(zeroCount == largestExp+1){
        cout << 0;
    }
    cout << "\n";
}

/*
    A Overloading operator for +
    @param ob, the refference of object that follows the + sign
    @return the Polynomial p
*/
Polynomial Polynomial::operator+(Polynomial const & ob){
    Polynomial *p= new Polynomial(largestExp);
        int* temp = new int[largestExp+1];
        for(int i = 0; i <= largestExp; i++){
            *(temp+i) = *(coef+i) + *(ob.getCoef()+i);
        }
        p->setCoef(temp);
    return p;
}

/*
    A Overloading operator for -
    @param ob, the refference of object that follows the - sign
    @return the Polynomial p
*/
Polynomial Polynomial::operator - (Polynomial const & ob){
    Polynomial *p= new Polynomial(largestExp);
        int* temp = new int[largestExp+1];
        for(int i = 0; i <= largestExp; i++){
            *(temp+i) = *(coef+i) - *(ob.getCoef()+i);
        }
        p->setCoef(temp);
    return p;
}

/*
    A Overloading operator for =
    @param ob, the refference of object that follows the = sign
    @return itself back
*/
Polynomial Polynomial::operator=(Polynomial const & ob){
    largestExp = ob.getLargestExp();
    coef = new int[largestExp+1];
    expo = new int[largestExp+1];
    if(!coef || !expo){
        cout << "Allocation error.\n";
        exit(1);
    }
    initialize();
    for(int i = 0; i <= largestExp; i++){
        *(coef+i) = *(ob.getCoef()+i);
        *(expo+i) = *(ob.getExpo()+i);
    }
    return this;
}

/*
    A Overloading operator for *
    @param ob, the refference of object that follows the * sign
    @return the Polynomial p;
*/
Polynomial Polynomial::operator*(Polynomial const &ob){
    Polynomial *p= new Polynomial((largestExp+1)*2);
        int* temp = new int[(largestExp+1)*2];
        for(int i = 0; i <= largestExp; i++){
            for(int j = 0; j <= largestExp; j++){
                int expoProduct = i+j;
                *(temp+expoProduct) += *(coef+j) * *(ob.getCoef()+i);
            }
        }
        p->setCoef(temp);
    return p;
}

//Polynomial Demo
int main(){
    cout << "****** Polynomial Calculator ******\n\n";
    bool endProgram = false;        // to continue or end the program
    int option;                     // user input for options
    char yOrN;                      // user input for yes and no
    int largestExp;                 // the largest exponent value
    bool endCalculation = false;    // to continue or end the calculation menu
    Polynomial p1(0);               // Fisrt Polynomial
    Polynomial p2(0);               // Second Polynomial
    while(!endProgram){

        //Input for Polynomials
        cout << "Enter your Polynomial in one line(press y) or by steps(press n): ";
        cin >> yOrN;
        switch(yOrN){
            case 'y': case 'Y':
            {
                string polyStr;

                //First Polynomial
                cout << "Please enter your first polynomial in this format (Ex: -4x^0 + x^1 + 4x^3 - 3x^4):\n";
                cin.ignore();
                getline(cin, polyStr);
                cout << "Please enter the largest exponent number: ";
                cin >> largestExp;
                p1 = new Polynomial(polyStr, largestExp);

                //Second Polynomial
                cout << "Please enter your second polynomial in this format (Ex: -4x^0 + x^1 + 4x^3 - 3x^4):\n";
                cin.ignore();
                getline(cin, polyStr); 
                cout << "Please enter the largest exponent number: ";
                cin >> largestExp;
                p2 = new Polynomial(polyStr, largestExp);
                break;
            }
            default:
            {
                //First Polynomial
                cout << "Please enter the largest exponent number for 1st polynomial: ";
                cin >> largestExp;
                int* coef1 = new int[largestExp+1];
                int* expo1 = new int[largestExp+1];
                for(int i = 0; i <=largestExp; i++){
                    cout << "Please enter the coeficient for exponent " << i << " : ";
                    cin >> *(coef1+i);
                    *(expo1+i) = 0;
                }
                p1 = new Polynomial(coef1, expo1, largestExp);

                //Second Polynomial
                cout << "Please enter the largest exponent number for 2st polynomial: ";
                cin >> largestExp;
                int* coef2 = new int[largestExp+1];
                int* expo2 = new int[largestExp+1];
                for(int i = 0; i <=largestExp; i++){
                    cout << "Please enter the coeficient for exponent " << i << " : ";
                    cin >> *(coef2+i);
                    *(expo2+i) = 0;
                }
                p2 = new Polynomial(coef2, expo2, largestExp);
                break;
            }
                
        }

        //Print 2 Polynomials on screen
        cout << "Polynomial 1: ";
        p1.print();
        cout << "Polynomial 2: ";
        p1.print();
        
        // Calculation menu
        while(!endCalculation){
            Polynomial answer(largestExp);
            cout << "\n";
            cout << "(1) Addition\n";
            cout << "(2) Subtraction\n";
            cout << "(3) Multiplication\n";
            cout << "(4) Assignment\n";
            cout << "(5) Exit\n";
            cout << "Please select an option: ";
            cin.ignore();
            cin >> option;

            //Select an option
            switch(option){

                //Addition
                case 1:
                {
                    answer = p1 + p2;
                    cout << "The result of addition:\n";
                    answer.print();
                    break;
                }

                //Subtraction
                case 2:
                {
                    answer = p1 - p2;
                    cout << "The result of subtraction:\n";
                    answer.print();
                    break;
                }

                //Multiplication
                case 3:
                {
                    answer = p1 * p2;
                    cout << "The result of multiplication:\n";
                    answer.print();
                    break;
                    break;
                }

                //Assignment
                case 4:
                {
                    int firstOrSecond;
                    string polyStr;
                    cout << "Would you like to reassign new values to the 1st or 2nd Polynomial?(Enter 1 or 2):\n";
                    cin >> firstOrSecond;
                    if(firstOrSecond == 1){
                        cout << "Please enter your polynomial in this format (Ex: -4x^0 + x^1 + 4x^3 - 3x^4):\n";
                        cin.ignore();
                        getline(cin, polyStr); 
                        cout << "Please enter the largest exponent number: ";
                        cin >> largestExp;
                        p1 = new Polynomial(polyStr, largestExp);
                    } else if(firstOrSecond == 2){
                        cout << "Please enter your polynomial in this format (Ex: -4x^0 + x^1 + 4x^3 - 3x^4):\n";
                        cin.ignore();
                        getline(cin, polyStr); 
                        cout << "Please enter the largest exponent number: ";
                        cin >> largestExp;
                        p2 = new Polynomial(polyStr, largestExp);
                    } else {
                        cout << "No polynomial was selected.\n";
                    }
                    break;
                }

                //Exit
                case 5:
                {
                    endCalculation = true;
                    endProgram = true;
                    break;
                }
            }
        }
    }
    return 0;
}