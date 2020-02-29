#include <iostream>
using namespace std;

int findMode(int *ptr, int length){
    int currentNum;
    int mode;
    int count[10] = {0,0,0,0,0,0,0,0,0,0};    //assume all int will be less than  10
    for(int i = 0; i < length; i++){
        currentNum = *ptr;
        count[currentNum]++;
        ptr++;
    }
    mode = 0;
    for(int j = 0; j < 10; j++){
        mode = count[j] > count[mode] ? j : mode;
    }
    return mode;
}

int main(){
    int array[10] = {1,1,1,2,2,3,3,4,5,6};
    int answer = findMode(array, 10);
    cout <<  answer << endl;
}