#include <iostream>
#include <cstring>
#include<string>
using namespace std;
need to update in the given string itself i.e. in input. No need to return or print.

string getCompressedString(string str){
    // Write your code here
    int i = 0;
    while(str[i] != '\0'){
        
        int count = 1;
        int j = i + 1;
        
        while((str[j] == str[i]) && (str[j + 1] == str[i])){
            count++;
            //left shift by one
            int k = j;
            for(k; str[k + 1] != '\0'; k++){
                str[k] = str[k + 1];
            }
            str[k] = '\0';
        }
        
        if((str[i] == str[j]) && (count == 1)){
            count++;
            str[j] = '0' + count;
        }
        else if(count > 1){
            count++;
            str[j] = '0' + count;
        }
        
        i++;
    }
    
    return str;
}

int main() {
    int size = 1e6;
    string str;
    cin >> str;
    str = getCompressedString(str);
    cout << str << endl;
}