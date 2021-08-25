#include <iostream>
#include<algorithm>
#include<climits>
using namespace std;

int findSecondLargest(int arr[], int n)
{
    sort(arr, arr + n);
    if(arr[0] == arr[n - 1])
        return INT_MIN;
    for(int i = n - 1; i >= 0; i--){
        if(arr[i] != arr[i - 1]){
            return arr[i - 1];
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
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findSecondLargest(input, size) << endl;

		delete[] input;
	}

	return 0;
}