//Sum of natural number
#include<iostream>
using namespace std;
int main(){
	int N;
	int sum1=0;
	int sum2=0;
	cout<<"Enter the number (range) of Natural number= "<<endl;
	cin>>N;
	for(int i=1;i<=N; i++){
		sum1=sum1+i;
	}
	cout<<"Printing value using for loop"<<endl;
	cout<<"Sum1 of "<<N<<" Natural number is "<<sum1<<endl;
	cout<<endl;
	sum2= (N*(N+1))/2;
	cout<<"Printing value using sum farmula"<<endl;
	cout<<"Sum2 of "<<N<<" Natural number is "<<sum2<<endl;
	return 0;
}
