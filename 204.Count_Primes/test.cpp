#include <bitset>
#include <iostream>
#include <cmath>
using namespace std;

int countPrimes(int n) {
	if(n == 0 || n == 1)
		return 0;
	bitset<1500000> arr;
	int count = 0;
	for(int i = 2;i < n;i++){
		if(!arr[i]){
			count++;
			for(long long int j = i * i; j < n;j += i){
				arr[j] = 1;
			}
		}
	}
	return count;
}

int main(){
	int n = 1500000;
	cout<<countPrimes(n);
	return 0;
}
