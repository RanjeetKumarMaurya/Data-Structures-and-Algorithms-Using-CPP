#include<bits/stdc++.h>
using namespace std;

int pow(int a, int n){
    if(n == 1){
        return a;
    }
    int f = pow(a, n / 2) * pow(a, n/ 2);
    if(n % 2 == 0){
        return f;
    }
    else{
        return a * f;
    }
}

int main(){
    int a, n;
    cin >> a >> n;
    cout << pow(a,n);
    return 0;
}