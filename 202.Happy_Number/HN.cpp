#include<bitset>
#include <iostream>
using namespace std;

bool isHappy(int n) {
    bitset<244> Pos,Neg,Temp;
	Pos[1] = 1;
	for(int i = 2;i < 244;i++){
		if(Neg[i] || Pos[i])
			continue;
		int j = i;
		while(!Temp[j]){
			int sum = 0;
			Temp[j] = 1;
			while(j != 0){
				int digit = j % 10;
				sum += digit * digit;
				j /= 10;
			}
			if(sum == 1){
				Pos |= Temp;
				break;
			}
			j = sum;
		}
		Neg |= Temp;
		Temp.reset();
	}
	while(n > 243){
		int m = n;
		int sum = 0;
		while(m != 0){
			int digit = m % 10;
			sum += digit * digit;
			m /= 10;
		}
		n = sum;
	}
	return Pos[n];
}

int main(){
	int n;
	cin>>n;
	if(isHappy(n))
		cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
