#include <iostream>
#include<climits>
using namespace std;

void findLargest(int **arr, int row, int col){

    if(row == 0){
        cout << "row" << " " << row << " " << INT_MIN;
        return;
    }
    
    int maxRowSum = 0;
    int maxColSum = 0;
    int rowIndex = 0;
    int colIndex = 0;
    
    for(int i = 0; i < row; i++){
        int rowSum = 0;
        for(int j = 0; j < col; j++){
            rowSum += arr[i][j];
        }
        if(rowSum > maxRowSum){
            maxRowSum = rowSum;
            rowIndex = i;
        }
    }
    
    for(int i = 0; i < col; i++){
        int colSum = 0;
        for(int j = 0; j < row; j++){
            colSum += arr[j][i];
        }
        if(colSum > maxColSum){
            maxColSum = colSum;
            colIndex = i;
        }
    }
    
    if(maxRowSum >= maxColSum){
        cout << "row" << " " << rowIndex << " " << maxRowSum;
    }
    else{
        cout << "column" << " " << colIndex << " " << maxColSum;
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int row, col;
		cin >> row >> col;

		int **input = new int *[row];
		for (int i = 0; i < row; i++)
		{
			input[i] = new int[col];
			for (int j = 0; j < col; j++)
			{
				cin >> input[i][j];
			}
		}

		findLargest(input, row, col);
		cout << endl;
	}
}