#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int set[], int sum, int n){
    bool subset[n + 1][sum + 1];

    //intialize array for base condition
    for(int i = 0; i < n + 1; i++){
        subset[i][0] = true;
    }
    for(int j = 1; j < sum + 1; j++){
        subset[0][j] = false;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - set[i - 1]];
        }
    }

    return subset[n][sum];
}

int main(){

    int n, sum;

    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> sum;

    cout << subsetSum(arr, sum, n) << endl;

    return 0;
}