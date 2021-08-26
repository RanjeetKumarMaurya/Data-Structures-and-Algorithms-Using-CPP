#include <iostream>
#include <cstring>
using namespace std;

int findSize(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

bool checkPalindrome(char str[]){
    int size = findSize(str);
    
    int i = 0;
    int j = size - 1;

    while(i <= j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}



int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome(str) ? "true" : "false");
}