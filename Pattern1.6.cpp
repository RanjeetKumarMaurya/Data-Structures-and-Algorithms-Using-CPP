#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int n;
    cin>>n;
    
    for(int i=65; i<(65+n); i++){
        int val=i;
        for(int j=65; j<=i; j++){
            cout<<char(val);
            val++;
        }
        cout<<endl;
    }
    return 0;
}



