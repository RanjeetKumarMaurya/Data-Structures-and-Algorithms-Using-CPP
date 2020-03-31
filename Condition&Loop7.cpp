#include<iostream>
using namespace std;

int main() {
	// Write your code here
    double bs;
    char grade;
    int allow;
    
    double ts;
    
    cin>>bs;
    cin>>grade;
    if(grade=='A'){
        allow=1700;
    }
    else if(grade=='B'){
        allow= 1500;
    }
    else{
        allow=1300;
    }
    
    double hra=0.2*bs;
    double da=0.5*bs;
    double pf=0.11*bs;
    
    ts=bs+hra+da+allow-pf;
    int fs=(int) ts;
    if((ts-fs)>=0.5){
        ts=ts+1;
    }
    else{
        ts=fs;
    }
    cout<<(int)ts<<endl;
}

