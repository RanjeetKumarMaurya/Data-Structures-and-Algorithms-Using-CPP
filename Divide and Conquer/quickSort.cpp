#include<iostream>
using namespace std;

//partition function
int partition(int arr[], int low, int high){
	int pivot = arr[low];
	int i = low;
	int j = low + 1;
	
	while((i <= high) && (j <= high)){
		if(arr[j] <= pivot){
			//swap i+1 with j and increase i and j
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			j++;
		}
		else{
			j++;
		}
	}
	
	//swap pivot with ith index value and return index i
	int temp = arr[low];
	arr[low] = arr[i];
	arr[i] = temp;
	
	return i;
}

//quicksort function
void quickSort(int arr[], int low, int high){
	if(low >= high){
		return;
	}
	
	int p = partition(arr, low, high); // call to partition array
	quickSort(arr, low, p - 1);
	quickSort(arr, p + 1, high);
}

//driver code
int main(){
	int n;
	cout << "Enter size of Array : " << endl;
	cin >> n;
	int arr[n];
	cout << "Enter  " <<n << " elements : " << endl;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	//print elements before sorting
	cout << "Elements before sorting : " << endl;
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	
	//call to sort array
	quickSort(arr, 0, n - 1);
	
	//print elements after sorting
	cout << "Elements after sorting : " << endl;
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	
	return 0;
}
