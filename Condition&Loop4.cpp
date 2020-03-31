//patter no 1
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i,j,val;
	i=1;
	j=1;
	val=1;
	for(i=1;i<=n;i++)
	{
		val=i;
		for(j=1;j<=i;j++)
		{
		    cout<<val;
			val++;	
		}
		cout<<endl;
	}
	return 0;
}
