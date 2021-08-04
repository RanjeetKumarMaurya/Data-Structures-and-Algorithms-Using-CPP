// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int firstElementKTime(int a[], int n, int k)
    {
        unordered_map<int, int> map;
        
        //populate map
        for(int i = 0; i < n; ++i){
            if(map.count(a[i]) > 0){
                int temp = map[a[i]];
                temp = temp + 1;
                if(temp == k){
                    return a[i];
                }
                map[a[i]] = temp;
            }
            else{
                if(k == 1){
                    return a[i];
                }
                map[a[i]] = 1;
            }
        }
        return -1;
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(a, n, k)<<endl;
	}
	
	return 0;
}  // } Driver Code Ends