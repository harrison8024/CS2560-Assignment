#include <iostream>
using namespace std;

int doSomething(int *x, int *y){
    int temp = *x; 
    int temp2 = *y;
    *x = temp2 * 10;
    *y = temp * 10;
    return *x + *y;
}

int main(){
    int a = 5;
    int b = 10;
    cout << a << " + " << b << endl;
    int answer = doSomething(&a, &b);
    cout << a << " + " << b << endl;
    cout << answer<< endl;
}