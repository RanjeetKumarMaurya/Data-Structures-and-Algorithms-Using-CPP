/*
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
 
Example 1: 
Input: 
8 8
0 1
1 2
2 3
3 4
4 5
5 6
4 7

Output: 1
Explanation: The given graph can be colored 
in two colors so, it is a bipartite graph.
Example 2:
 
Your Task:
You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of graph and returns a boolean value true if graph is bipartite otherwise returns false.

Expected Time Complexity: O(V)
Expected Space Complexity: O(V)

Constraints:
1 ≤ V, E ≤ 10^5
*/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool visited[100001];
    int color[100001];
    
    bool isBipartiteUtil(int sv, vector<int> adj[]){
        queue<int> q;
        q.push(sv);
        color[sv]=0;
        
        while(q.size()!=0){
            int node = q.front();
            visited[node]=true;
            q.pop();
            for(auto i : adj[node]){
                if(color[i]==-1){
                    color[i]=1-color[node];
                    q.push(i);
                }
                else{
                    if(color[i]==color[node]) return false;
                }
            }
        }
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    memset(visited, false, sizeof(visited));
	    memset(color, -1, sizeof(color));
	    for(int i = 0; i < V; ++i){
	        if(!visited[i])
	            if(isBipartiteUtil(i, adj)==false) return false;
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends