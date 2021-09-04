#include<bits/stdc++.h>
using namespace std;

void bfs(bool** edges, int s, int n, bool* &visited){
    queue<int> pendingQueue;
    pendingQueue.push(s);

    while(pendingQueue.size()){
        int front = pendingQueue.front();
        pendingQueue.pop();
        visited[front] = true;

        for(int i = 0; i < n; i++){
            if( (i != front) && (edges[front][i] == true) && (visited[i] == false) )
                pendingQueue.push(i);
        }
    }
}

bool isConnected(bool** edges, int s, int n){

    //make a visited array and intialize it with false
    bool* visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }

    bfs(edges, s, n, visited);

    //if any node is not visited print o otherwise print 1
    for(int i = 0; i < n; i++){
        if(visited[i] == false)
            return false;
    }
    return true;
}

int main(){
    int n, e;
    
    //fix size of garph
    cin >> n;
    //number of edges 
    cin >> e;

    //create n edges and n x n matrix and intialize it with 0
    bool **edges = new bool*[n];
    for(int i = 0; i< n; i++){
        edges[i] = new bool[n];
        for(int j = 0; j < n; j++){
            edges[i][j] = false;
        }
    }

    //fill edges
    for(int i = 0; i < e; i++){
        int f, t;
        cin >> f >> t;
        edges[f][t] = true;
        edges[t][f] = true;
    }

    //check if connected
    cout << "Is graph connected? " << isConnected(edges, 0, n) << endl;
}