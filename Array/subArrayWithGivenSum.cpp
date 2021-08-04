// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        // Your code here
        int p1 = 0;
        int p2 = 0;
        vector<int> ans;
        long long sum = 0;
        
        for(int i = -1; i < n;){
            if(sum < s){
                sum += arr[++i];
                p2 = i;
            }
            else if(sum > s){
                sum -= arr[p1];
                p1 += 1;
            }
            
            if(sum == s){
                ans.push_back(p1 + 1);
                ans.push_back(p2 + 1);
                return ans;
            }
        }
        ans.push_back(-1);
        return ans;
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends