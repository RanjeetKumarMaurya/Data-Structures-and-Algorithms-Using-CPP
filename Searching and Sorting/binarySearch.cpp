#include <iostream>
using namespace std;

// arr - input array
// n - size of array
// val - element to be searched
/*int BinarySearch(int arr[], int n, int val){}*/	

int binarySearchHelper(int arr[], int si, int ei, int val){
    int mid = ((si + ei) / 2);
    
    if(arr[mid] == val){
        return mid;
    }
    
    if(ei < si){
        return -1;
    }
    
    if(arr[mid] > val){
        binarySearchHelper(arr, 0, mid - 1, val);
    }
    else{
        binarySearchHelper(arr, mid + 1, ei, val);
    }
    
    //return -1;
}

int binarySearch(int arr[], int n, int val)
{   
    int index = binarySearchHelper(arr, 0, n - 1, val);
    return index;
}


//driver code
int main()
{

	int size;
	cin >> size;
	int *input = new int[size];

	for(int i = 0; i < size; ++i)
	{
		cin >> input[i];
	}
	
	int t;
	cin >> t;

	while (t--)
	{
		int val;
		cin >> val;
		cout << binarySearch(input, size, val) << endl;
	}
	
	delete [] input;
	return 0;
}