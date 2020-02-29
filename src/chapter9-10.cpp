#include <iostream>
using namespace std;

int * reverse(int *ptr, int length){
    static int newArray[10];
    for(int i = length - 1; i >= 0; i--){
        newArray[i] = *ptr;
        ptr++;
    }
    return newArray;
}

int main (){
    int array[10] = {1,1,1,2,2,3,3,4,5,6};
    int *newArray = reverse(array, 10);
    for(int i = 0; i < 10; i ++){
        cout << *newArray << endl;
        newArray++;
    }
}