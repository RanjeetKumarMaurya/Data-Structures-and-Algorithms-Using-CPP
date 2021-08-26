#include <iostream>
#include <cstring>
using namespace std;

int len(char input[],int i)
{
	int count=0;
	while(input[i]!=' '&&input[i]!='\0')
	{
		count++;
		i++;
	}
	return count;
}
void reverse(char input[],int i,int j)
{
	while(i<j)
	{
		char temp=input[i];
		input[i]=input[j];
		input[j]=temp;
		i++;
		j--;
	}
}
void reverseEachWord(char input[])
{
	int i=0;
	int k=-2;
	int j=0;
	while(input[j]!=0)
	{
		k=k+len(input,i)+1;
		reverse(input,i,k);
			i=k+2;
			j=k+1;
	}
}

int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}