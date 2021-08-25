#include <iostream>
using namespace std;

void pushZeroesEnd(int input[], int size){
    int i = 0;
    int j = 1;
    
    while(i < size){
        while(input[i] != 0){
            i++;
            j++;
        }
        while(j == 0){
            j++;
        }
        
        //swap i and j
        input[i] = input[i] + input[j];
        input[j] = input[i] - input[j];
        input[i] = input[i] - input[j];
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

		pushZeroesEnd(input, size);

		for (int i = 0; i < size; i++)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}

	return 0;
}