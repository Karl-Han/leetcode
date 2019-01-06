#include <iostream>
using namespace std;

double FastPow(double x,long n){
	if(n == 1)
		return x;
	if(n & 1)
		return x * FastPow(x*x,n/2);
	return FastPow(x*x,n/2);
}

int main(){
	double x = 0;
	int n = 0;
	cin>>x>>n;
	long bigger = n;
	if(n < 0){
		x = 1 / x;
		bigger = -bigger;
	}
	cout<<FastPow(x,bigger)<<endl;
	return 0;
}
