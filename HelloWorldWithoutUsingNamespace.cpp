//without using namespace
#include<iostream>
int main(){
	int a;
	std::cout<<"Enter the value of 'a' = ";
	std::cin>>a;
	if(a<10){
			std::cout<<"Hello World without using namespace standard.";
			std::cout<<std::endl;
			}
			else{
				std::cout<<"You have missed something, please re-execute and re-enter the value.";
			}
	return 0;
}
