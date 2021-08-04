#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//relative sorting
vector<int> relativeSort(int* A1, int n, int* A2, int m){
    vector<int> output;
    int *visited = new int[n];
    //make visited valse
    for(int i = 0; i < n ; ++i){
        visited[i] = false;
    }
    //sort A1
    sort(A1, A1 + n);

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if((A1[j] == A2[i]) && (!visited[j])){
                output.push_back(A1[j]);
                visited[j] = true;
            }
        }
    }

    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            output.push_back(A1[i]);
        }
    }

    delete []visited;
    return output;
}

int main(){
    int n, m;
    cin >> n >> m;

    int *A1 = new int[n];
    int *A2 = new int[m];

    //populate array
    for(int i = 0; i < n; i++){
        cin >> A1[i];
    }

    for(int i = 0; i < m; i++){
        cin >> A2[i];
    }

    vector<int> output = relativeSort(A1, n, A2, m);

    for(int i = 0; i < output.size(); ++i){
        cout << output[i] << " ";
    }

    delete []A1;
    delete []A2;
    output.clear();
    return 0;
}