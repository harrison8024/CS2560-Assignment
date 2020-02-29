#include <iostream>
using namespace std;

#define SIZE_OF_ARRAY (10)

int * sizeUp(int *ptr, int length){
    static int newArray[SIZE_OF_ARRAY * 2];
    for(int i = 0; i < length; i++){
        newArray[i] = *ptr;
        ptr++;
    }
    for(int j = length; j < SIZE_OF_ARRAY * 2; j++){
        newArray[j] = 0;
    }
    return newArray;
}

int main(){
    int array[10] = {1,1,1,2,2,3,3,4,5,6};
        int *newArray = sizeUp(array, 10);
        for(int i = 0; i < SIZE_OF_ARRAY*2; i ++){
            cout << *newArray << endl;
            newArray++;
        }
}