#include <stdio.h>
#include<stdlib.h>

int main(){
	int fac = 1;
	for(int j = 0;j < 50;j++){
		for(int i = 2;i < 10;i++){
			fac = fac * i;
			while(!(fac %10))
				fac /= 10;
			fac %= 10;
			printf("%d ",fac);
		}
		printf("\n");
	}
	return 0;
}
