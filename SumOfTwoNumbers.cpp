//Adding two numbers without using std namespace
#include<iostream>
int main(){
	int a, b;
	std::cout<<"Enter two number 'a' and 'b' = ";
	std::cin>>a>>b;
	std::cout<<std::endl;
	int sum= a+b;
	std::cout<<"Sum of "<<a<<" and "<<b<<" is "<<sum;
	return 0;
}
