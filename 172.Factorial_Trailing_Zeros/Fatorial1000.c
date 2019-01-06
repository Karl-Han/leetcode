#include <stdio.h>
#include <stdlib.h>
#include <string.h>

short digit[10000];
int length = 0;

/*
 * TO DO
 * 1. Improve the efficiency by decreasing the postion to multiply.
 *
 */

void fatorial(int fac){
	memset(digit,0,sizeof(short)*10000);
	digit[0] = 1;
	int carry = 0;
	int sum = 0;
	//int pos = 1;
	for(int i = 2;i <= fac;i++){
		;
		//int newpos = 0;
		for(int j = 0;j < 10000;j++){
			sum = i * digit[j] + carry;
			digit[j] = sum % 10;
			carry = sum / 10;
		}
	}
	length = 9999;
	while(digit[length] == 0){
		length--;
	}
}

int countZeros(int n){
	int count = 0;
	int count1 = 0;
	while(n){
		count += (n /= 5);
		count1 += (n /= 5);
	}
	return count + count1;
}

int main(){
	int des;
	scanf("%d",&des);
	for(int i = 2;i < des;i++){
		if(!((i-1) % 10))
			printf("\n");
		fatorial(i);
		printf("%d ",digit[countZeros(i)]);
	}
	return 0;
}
