// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


 // } Driver Code Ends
//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        //Your code here
        vector<int> tempOutput;
        vector<int> finalOutput;
        unordered_map<int, int> map;

        //construct map using A1
        for(int i = 0; i < N; i++){
            if(map.count(A1[i]) > 0){
                int temp = map[A1[i]];
                temp++;
                map[A1[i]] = temp;
            }
            else{
                map[A1[i]] = 1;
            }
        }

        //Find A2 in map and put it in final output
        for(int i = 0; i < M; ++i){
            if(map.count(A2[i]) > 0){
                int temp = map[A2[i]];
                for(int j = 0; j < temp; ++j){
                    finalOutput.push_back(A2[i]);
                }
                map.erase(A2[i]);
            }
        }

        unordered_map<int, int>::iterator it = map.begin();
        while (it != map.end())
        {
            int temp = it->second;
            for(int i = 0; i < temp; ++i){
                tempOutput.push_back(it->first);
            }
            it++;
        }
        
        //sort tempOutput
        sort(tempOutput.begin(), tempOutput.end());

        //copy into final output
        for(int i = 0; i < tempOutput.size(); ++i){
            finalOutput.push_back(tempOutput[i]);
        }
        
        //delete tempoutput
        tempOutput.clear();

        /*
        unordered_map<int, int>::iterator it = map.begin();
        while(it!=map.end()){
            cout << it->first << " " << it->second << endl;
            it++;
        }
        */

    return finalOutput;  
    } 
};

// { Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 
  // } Driver Code Ends