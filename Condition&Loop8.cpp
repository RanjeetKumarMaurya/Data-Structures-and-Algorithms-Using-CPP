#include<iostream>
using namespace std;

int main() {
	// Write your code here
    int n;
    cin>>n;
    int evenSum=0;
    int oddSum=0;
    
    while(n!=0){
        int r= n%10;
        if(r%2==0){
            evenSum+=r;
        }
        else{
            oddSum+=r;
        }
        n=n/10;
    }
    cout<<evenSum<<"   "<<oddSum<<endl;
}

