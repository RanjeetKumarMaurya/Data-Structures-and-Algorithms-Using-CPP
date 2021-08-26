#include <iostream>
#include <cstring>
using namespace std;

int getSize(char *input){
    int i = 0;
    while(input[i] != '\0'){
        i++;
    }
    return i;
}
void trimSpaces(char input[]) {
    int size = getSize(input);
    int i = 0;
    while(input[i] != '\0'){
        if(input[i] == ' '){
            for(int j = i; j < size; j++){
                input[j] = input[j + 1];
            }
            input[size - 1] = '\0';
            size = size - 1;
        }
        else{
            i++;
        }
    }
}

int main() {
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}

