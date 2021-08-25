#include <iostream>
#include<algorithm>
using namespace std;

int arrayRotateCheck(int input[], int size)
{
    int i = size - 1;
    int comp = input[size - 1];
    
    sort(input, input + size);
    
    int j = size - 1;
    while(input[j] != comp){
        j--;
    }
    
    return i - j;
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

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	}
	
	return 0;
}