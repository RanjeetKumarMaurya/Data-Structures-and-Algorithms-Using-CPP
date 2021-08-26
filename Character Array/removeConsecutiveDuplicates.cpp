#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char input[])
{
     int i=0;
     int j=0;
     while(input[i]!=0)
     {
     	if(input[i]==input[i+1])
     	{
     		i++;
		 }
		 else
		 {
		 	input[j]=input[i];
		 	j++;
		 	i++;
		 }
	 }
	 input[j]='\0';
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}