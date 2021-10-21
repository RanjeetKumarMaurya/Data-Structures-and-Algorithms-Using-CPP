/*
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

Example 1:

Input:   
5 5
0 1
1 2
2 3
3 4
4 1
Output: 1
Explanation: 1->2->3->4->1 is a cycle.

Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.

NOTE: The adjacency list denotes the edges of the graph where edges[i][0] and edges[i][1] represent an edge.

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

Constraints:
1 ≤ V, E ≤ 10^5
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool visited[100001];
    
    //using DFS
    bool isCycleUtil(int node, int parent, vector<int> adj[]){
        visited[node] = 1; 
        for(auto it: adj[node]) {
            if(!visited[it]) {
                if(isCycleUtil(it, node, adj)) 
                    return true; 
            }
            else if(it!=parent) 
                return true; 
        }
        
        return false; 
    }
    
    bool isCycle(int V, vector<int> adj[]){
        memset(visited, false, sizeof(visited));
	    for(int i = 0;i<V;i++) {
	        if(!visited[i]) {
	            if(isCycleUtil(i, -1, adj)) return true; 
	        }
	    }
	    return false; 
    }
    
    //Using BFS
    /*bool isCycleUtil(int sv, vector<int> adj[]){
        queue<pair<int, int>> q;
        q.push({sv, -1});
        visited[sv]=true;
        while(q.size()!=0){
            int sv = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto i : adj[sv]){
                if(!visited[i]){
                    visited[i]=true;
                    q.push({i, sv});
                }
                else
                if(i!=parent) return true;
                   
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < V; ++i){
            if(visited[i]==false)
                if(isCycleUtil(i, adj)) return true;
        }
        return false;
    }*/
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends