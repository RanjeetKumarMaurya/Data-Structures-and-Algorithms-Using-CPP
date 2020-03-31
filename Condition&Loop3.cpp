//farenhite to celcius
#include<iostream>
using namespace std;
int ftc(int);
int main()
{
	int start,end,step;
	int i,c1;
	cin>>start>>end>>step;
	for(i=start;i<=end;i=i+step)
	{
		c1=ftc(i);
		cout<<i<<"\t"<<c1<<endl;
	}
	return 0;
}
int ftc(int f)
{
	int c;
	c=((f-32)*5)/9;
	return c;
}
