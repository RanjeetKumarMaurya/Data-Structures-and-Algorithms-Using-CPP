//Array program with size MAX
#include<iostream>
#include<stdlib.h>
using namespace std;
#define max 100 //If more number of array of MAX size the all can be changed simultaneously at a time

int main(){
	int arr[max];
	int sum=0, i, count=0, element;
	cout<<"Enter the no of elements : ";
	cin>>count;
	cout<<endl;
	for(i=0; i<count; i++){
		cout<<"Enter "<<i<<" th position element : ";
		cin>>element;
		arr[i]=element;
		sum+= arr[i];
	}
	cout<<"Sum of the array is = "<<sum<<endl;
	return 0;
}
