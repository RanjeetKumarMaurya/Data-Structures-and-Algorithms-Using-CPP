#include<bits/stdc++.h>
using namespace std;

int countOfSubsetSum(int arr[], int sum, int n){

    //create a table and intialise it for base condition
    int table[n + 1][sum + 1];
    for(int i = 0; i < n + 1; i++){
        table[i][0] = 1;
    }
    for(int i = 1; i < sum + 1; i++){
        table[0][i] = 0;
    }

    //iterate over table and check for all the value

    for(int i = 1; i < n + 1; i++){
        for(int j = 0; j < sum + 1; j++){
            if(arr[i - 1] > j) table[i][j] = table[i - 1][j];
            else table[i][j] = table[i - 1][j - arr[i - 1]] + table[i - 1][j];
        }
    }

    return table[n][sum];
}

int main(){

    int n, sum;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cin >> sum;

    cout << countOfSubsetSum(arr, sum, n) << endl;

    return 0;
}