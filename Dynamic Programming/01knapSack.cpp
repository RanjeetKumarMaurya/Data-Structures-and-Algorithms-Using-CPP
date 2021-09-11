#include<bits/stdc++.h>
using namespace std;

//create a array to keep record at each step
static int table[1002][1002];

inline int max(int a, int b){
    return a > b ? a : b;
}

int knapsack(int *weight, int w, int *value, int n){
    if(n == 0 || w == 0){
        return 0;
    }

    if(table[n - 1][w] != -1){
        return table[n - 1][w];
    }

    if(weight[n - 1] > w){
        return table[n - 1][w] = knapsack(weight, w, value, n - 1);
    }
    else{
    return table[n - 1][w] = max( (value[n - 1] + knapsack(weight, w - weight[n - 1], value, n - 1)), (knapsack(weight, w, value, n - 1)) );
    }
}

int main(){
    memset(table, -1, sizeof(table));
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