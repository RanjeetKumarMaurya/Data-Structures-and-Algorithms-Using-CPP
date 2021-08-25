#include <iostream>
#include<valarray>
#include <algorithm>
using namespace std;

void sort012(int arr[], int n)  {
    int lo = 0;
    int hi = n - 1;
    int mid = 0;
 
    while (mid <= hi) {
        switch (arr[mid]) {
 
        case 0:
            swap(arr[lo++], arr[mid++]);
            break;
 
        case 1:
            mid++;
            break;
 
        case 2:
            swap(arr[mid], arr[hi--]);
            break;
        }
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;

		cin >> size;
		int *arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		sort012(arr, size);

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		delete[] arr;
		cout << endl;
	}

	return 0;
}