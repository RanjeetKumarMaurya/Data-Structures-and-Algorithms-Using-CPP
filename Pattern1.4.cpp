//reverse no pattern
#include<iostream>
using namespace std;
int main()
{
	int n;
    cin>>n;
    int val;
    
    for(int i=1; i<=n; i++){
        val=i;
        for(int j=1; j<=i; j++){
            cout<<val;
            val = val-1;
        }
        cout<<endl;
    }
    return 0;
}

