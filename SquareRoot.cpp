//Square root of a number
#include<iostream>
#include<cmath> //<cmath> is c header used here in c++ with an prefix c before math header
int main(){
	double a;
	std::cout<<"Enter a number= ";
	std::cin>>a;
	int sqrt_x= sqrt(a);
	std::cout<<"Square root of "<<a<<" is "<<sqrt_x;
	return 0;
}
