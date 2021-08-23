#include <iostream>
using namespace std;

void merge(int arr1[], int size1, int arr2[], int size2, int ans[]){
    
    int i = 0;
    int j = size1 - 1;
    int k = 0;
    int l = size2 - 1;
    int m = 0;
    
    while(i <= j && k <= l){
        if(arr1[i] < arr2[k]){
            ans[m] = arr1[i];
            i++;
            m++;
        }
        else{
            ans[m] = arr2[k];
            m++;
            k++;
        }
    }
    
    if(i <= j){
        while(i <= j){
            ans[m] = arr1[i];
            i++;
            m++;
        }
    }
    else{
        while(k <= l){
            ans[m] = arr2[k];
            k++;
            m++;
        }
    }
}


int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size1;
		cin >> size1;

		int *arr1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> arr1[i];
		}

		int size2;
		cin >> size2;

		int *arr2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> arr2[i];
		}

		int *ans = new int[size1 + size2];

		merge(arr1, size1, arr2, size2, ans);

		for (int i = 0; i < size1 + size2; i++)
		{
			cout << ans[i] << " ";
		}

		cout << endl;
		delete[] arr1;
		delete[] arr2;
		delete[] ans;
	}
}