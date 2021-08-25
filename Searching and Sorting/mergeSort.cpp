#include<iostream>
using namespace std;

//function to merge two sorted array
void merge(int arr[], int si, int ei){
	//cout << "\nIn Merge : from " << si << " index to " << ei << " index " << endl; //log
	
	int mid  = (si + ei) / 2;
	int m = 0;
	int i = si, j = mid, k = mid + 1, l = ei;
	int tempArr[ei - si + 1];
	
	while((i <= j) && (k <= l)){
		if(arr[i] < arr[k]){
			tempArr[m] = arr[i];
			m++;
			i++;
		}
		else{
			tempArr[m] = arr[k];
			k++;
			m++;
		}
	}
	
	if(i <= j){
		while(i <= j){
			tempArr[m] = arr[i];
			m++;
			i++;
		}
	}
	else{
		while(k <= l){
			tempArr[m] = arr[k];
			k++;
			m++;
		}
	}
	
	//merge sorted temp. array into main array
	m = 0;
	for(si; si <= ei; si++){
		arr[si] = tempArr[m];
		m++;
	}
}

//function to mergeSort subarray
void mergeSort(int arr[], int si, int ei){
	if(si >= ei){
		//cout << "\nfrom " << si << " index to " << ei << " index " << endl;  //log
		return;
	}
	
	//cout << "\nfrom " << si << " index to " << ei << " index " << endl;  //log
	int mid = (ei + si) / 2;
	mergeSort(arr, si, mid);
	//cout << "Called" << endl;
	mergeSort(arr, mid + 1, ei);
	merge(arr, si, ei);
	//cout << "\nI am touching this line" << endl;
}

int main(){
	int n;
	cout << "Enter size of array : ";
	cin >> n;
	
	int arr[n];
	
	cout << "\nEnter " << n << " Elements : ";
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	cout << "\nArray before sorting : ";
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	
	mergeSort(arr, 0, n-1);  //call to merge
	
	cout << "\nArray after sorting : ";
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
}
