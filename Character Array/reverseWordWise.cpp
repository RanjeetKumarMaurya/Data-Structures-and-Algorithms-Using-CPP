#include <iostream>
using namespace std;

int len(char *input){
    int i = 0;
    while(input[i] != '\0'){
        i++;
    }
    return i;
}

void swap(char *input, int i, int j){
    char temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}

void reverse(char *input, int i, int j){
	while(i <= j){
        swap(input, i, j);
        i++;
        j--;
    }    
}

void reverseStringWordWise(char input[]) {
    // Write your code here
    int i = 0;
    int j = len(input) - 1;
    
    while(i <= j){
        swap(input, i,j);
        i++;
        j--;
    }
    
    i = 0;
    j = 0;
    while(input[j] != '\0'){
    	if((input[j + 1] == ' ') || (input[j + 1] == '\0')){
            reverse(input, i, j);
            j += 2;
            i = j;
        }
        else{
            j++;
        }
    }
}

int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
