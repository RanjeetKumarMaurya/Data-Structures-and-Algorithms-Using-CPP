// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
#include<cstdlib>
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    vector<int> output;
        unordered_map<char, int> map;

        //construct map using A1
        for(int i = 0; i < s.length(); i++){
            if(map.count(s[i]) > 0){
                int temp = map[s[i]];
                temp++;
                map[s[i]] = temp;
            }
            else{
                map[s[i]] = 1;
            }
        }
        
        //checking
        /*
        unordered_map<char, int>::iterator it = map.begin();
        while(it!=map.end()){
            cout << it->first << " " <<it->second << endl;
            it++;
        }
        */
        
        
        
        bool firstFail = false;
        bool secondFail = false;
        int firstFailValue = 0;
        int secondFailValue = 0;
        
        unordered_map<char, int>::iterator it = map.begin();
        int comp = it->second;
        it++;
        
        while(it != map.end()){
            
            if((it->second) != comp){
                if((comp > 1) && (it->second >1) && abs(comp - (it->second)) > 1){
                    //cout << abs(comp - it->second)<< endl;
                    return false;
                }
                else if(!firstFail){
                    firstFail = true;
                    firstFailValue = it->second;
                }
                else if(!secondFail){
                    if(firstFailValue != it->second){
                        secondFail = true;
                    }
                }
            }
            it++;
        }
        if(firstFail && secondFail){
            return false;
        }
        else{
            return true;
        }
  }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}


  // } Driver Code Ends