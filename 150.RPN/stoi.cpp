#include <cstring>
#include <iostream>

int main(){
	std::string str = "20181024";
	int single = 1111;
	int parseStr = std::stoi(str);
	std::cout<<"20181024*1111 = "<<(long)20181024*1111<<std::endl;
	std::cout<<(long)parseStr * single<<std::endl;
	std::string operatorr = "*";
	std::cout<<(int)'2'<<" is "<<(int)str[0]<<" And * is "<<(int)operatorr[0]<<std::endl;
	char ch = (int)str[0];
	std::cout<<ch<<std::endl;
	return 0;
}
