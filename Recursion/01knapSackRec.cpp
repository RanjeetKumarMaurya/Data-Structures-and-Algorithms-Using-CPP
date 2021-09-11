#include<bits/stdc++.h>
using namespace std;


inline int max(int a, int b){
    return a > b ? a : b;
}

int knapsack(int *weight, int w, int *value, int n){
    if(n == 0 || w == 0){
        return 0;
    }

    if(weight[n - 1] > w){
        return knapsack(weight, w, value, n - 1);
    }
    else
    {
    return max( (value[n - 1] + knapsack(weight, w - weight[n - 1], value, n - 1)), (knapsack(weight, w, value, n - 1)) );
    }
}

int main(){
    int n, w;
    cin >> n;
    int *weight = new int[n];
    int *value = new int[n];

    for(int i = 0; i < n; i++){
        cin >> weight[i];
    }
    for(int i = 0; i < n; i++){
        cin >> value[i];
    }

    cin >> w;
    cout << knapsack(weight, w, value, n);

    return 0;
}