#include<bits/stdc++.h>
using namespace std;

bool hasPath(bool **edges, int sv, int ev, int size){
    queue<int> pendingQueue;
    pendingQueue.push(sv);
    bool *visited = new bool[size];
    for(int i = 0; i < size; i++)
        visited[i] = false;


    while(pendingQueue.size() != 0){
        int front  = pendingQueue.front();
        pendingQueue.pop();
        visited[front] = true;

        if(front == ev)
            return true;

        for(int i = 0; i < size; i++){
            if( (i != front) && (edges[front][i] == true) && (visited[i] == false) ){
                if(i == ev)
                    return true;
                pendingQueue.push(i);
            }
        }
    }
    return false;
}


int solve(int A, vector<vector<int> > &B) {

    //create grapgh of A nodes ranging from 0 to A-1
    bool **edges = new bool*[A];
    for(int i = 0; i < A; i++){
        edges[i] = new bool[A];
        for(int j = 0; j < A; j++){
            edges[i][j] = false;
        }
    }


    //fill edges between nodes
    for(int i = 0; i < B.size(); i++){
        edges [B[i][0] - 1] [B[i][1] - 1] = true;
    }

    bool res = hasPath(edges, 0, A - 1, A);
    return res;
}

int main(){
    int A;
    cin >> A;
    vector<vector<int>> B;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        B.push_back({a, b});
    }

    cout << solve(A, B);

    return 0;
}