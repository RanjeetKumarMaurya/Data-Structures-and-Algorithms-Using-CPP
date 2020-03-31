//Vecotr array
#include<iostream>
#include<vector>
using namespace std;
#define MAX 100

int main(){
	vector<int> arr(MAX);  //Define time size
	int count, i, sum=0, element;
	cout<<"Enter no of elements : "<<endl;
	cin>>count;
	for(i=0; i<count; i++){
		
		cout<<"Enter "<<i<<" th position element :";
		cin>>element;
		arr[i]=element;
		cout<<endl;
		sum+=arr[i];
	}
	cout<<"Sum of the array is = "<<sum<<endl;
	return 0;
}
