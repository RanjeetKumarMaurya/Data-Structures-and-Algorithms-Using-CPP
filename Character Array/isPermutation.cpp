#include <iostream>
#include <cstring>
#include<unordered_map>
using namespace std;

int length(char *str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

bool isPermutation(char input1[] , char input2[]){
    unordered_map<char, int> map;
    
    //fill map using string 1
    int len = length(input1);
    for(int i = 0; i < len; i++){
        if(map.count(input1[i]) > 0){
            map[input1[i]]++;
        }
        else{
            map[input1[i]] = 1;
        }
    }
    
    //delete map using string 2
    len = length(input2);
    for(int i = 0; i < len; i++){
        if(map.count(input2[i]) == 0){
            return false;
        }
        else if(map.count(input2[i]) > 0){
            map[input2[i]]--;
            if(map.count(input2[i]) == 0){
                map.erase(input2[i]);
                cout << map.size() << endl;
            }
        }
    }
    
    if(map.size() > 0){
        return false;
    }
    else{
        return true;
    }
}

int main() {
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");
}