#include<iostream>
using namespace std;

int main() {
	// Write your code here
    int num;
    int pow;
    int val=1;
    cin>>num>>pow;
    
    if(pow==0){
        cout<<"1"<<endl;
    }
    else{
        while(pow>=1){
            val=val*num;
            pow =pow-1;
        }
        cout<<val<<endl;
    }
}

