//pattern no 2 
#include<iostream>
using namespace std; 
int main()
{
	int i,j,k,n,val;
	i=1;j=1;val=1;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		val=i;
	    for(k=1;k<=n-i;k++)
	    {
	    	cout<<" ";
		}
		for(j=1;j<=i;j++)
		{
			cout<<val;
			val++;
		}
		cout<<endl;
	}
	return 0;
}
