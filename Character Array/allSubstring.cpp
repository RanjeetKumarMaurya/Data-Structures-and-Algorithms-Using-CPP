#include <iostream>
#include <cstring>
using namespace std;

int findLen(char *str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

void print(char *str, int i, int j){
	for(i; i <= j; i++){
        cout << str[i];
   }
    cout << endl;
}

void printSubstrings(char str[]){
    int len = findLen(str);
    
    for(int i = 0; i < len; i++){
        for(int j = i; j < len; j++){
            print(str, i, j);
        }
    }
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    printSubstrings(str);
}