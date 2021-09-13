#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int sum, int n){
    //make 2D array of size n+1 and sum+1 and intialize array for base condition
    bool subset[n + 1][sum + 1];
    for(int i = 0; i < n + 1; i++){
        subset[i][0] = true;
    }
    for(int i = 1; i < sum + 1; i++){
        subset[i][0] = false;
    }

    //check for each value in i x j row and column

    for(int i = 1; i < n + 1; i++){
        for(int j = 0; j < sum + 1; j++){
            if(arr[i - 1] > j){
                subset[i][j] = subset[i - 1][j];
            }
            else{
                subset[i][j] = subset[i - 1][j - arr[i - 1]] || subset[i - 1][j];
            }
        }
    }

    return subset[n][sum];
}

bool equalSumPartition(int arr[], int n){
    int arraySum = 0;
    for(int i = 0; i < n; i++){
        arraySum += arr[i];
    }

    if(arraySum % 2 != 0){
        return false;
    }

    return subsetSum(arr, arraySum / 2, n);
}

int main(){
    int n, sum;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << equalSumPartition(arr, n) << endl;

    return 0;
}