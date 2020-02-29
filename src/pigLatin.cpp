#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;   //user input
    string output = "";  //output pig latin
    cout << "Pig Latin Converter:\n"; //Prompt
    cout << "English: ";
    getline(cin,input);
    int index = 0;
    string word = "";
    cout << "Pig Latin: ";

    // iterate thru string from input
    while(index < input.length()){
        // find each word by space
        word += input[index];
        // if the word ends or end of the input, it will convert the word to pig latin
        if(input[index] == ' ' || index == input.length() - 1){
            for(int i = 1; i < word.length() - 1; i++){
                output += toupper(word[i]);
            }
            output += toupper(word[0]);
            output += "AY ";
            word = "";
        }
        index++;
    }
    cout << output << endl;
    return 0;
}