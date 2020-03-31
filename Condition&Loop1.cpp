#include<iostream>
using namespace std;

int main() {
	// Write your code here
    
	char upper[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char lower[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char input;
    cin>>input;
    
    for(int i=0; i<(sizeof(upper)/sizeof(upper[0])); i++)
    {
        if(upper[i]==input)
        {
            cout<<"1"<<endl;
            return 0;
        }
        else if(lower[i]==input)
        {
            cout<<"0"<<endl;
            return 0;
        }
        else
        {
            if(i==((sizeof(upper)/sizeof(upper[0]))-1))
               {
                   cout<<"-1"<<endl;
                   return 0;
               }
               else
               {
                   continue;
               }
        }
    }
    return 0;
}
