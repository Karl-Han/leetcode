/*
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (27.17%)
 * Total Accepted:    182.7K
 * Total Submissions: 672.4K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */
long int FastPowerMod(int mod, long base,long power){
	//printf("base = %lu,power = %lu,mod = %lu\n",base,power,mod);
	long res = 1;
	base %= mod;
	while(power > 0){
		if(power & 1)
			res = (res * base) % mod;
		power >>= 1;
		base = (base*base) % mod;
		//printf("base = %lu,power = %lu,res = %lu\n",base,power,res);
	}
	//printf("res = %lu\n",res%mod);
	return res;
}
bool passMullerRabin(int num,int testNum){
	long d = (num-1)>>1;
	while(!(d & 1))
		d >>=1;
	long int x = FastPowerMod(num,testNum,num-1);
	if(x != 1)
		return 0;
	while(d != num-1){
		x = (x * x) % num;
		if(!(x == 1 || x == num-1))
			return 0;
		d <<=1;
	}
	return 1;
}
bool isPrime(int num,int times){
	if(num == 2)
		return 1;
	if(num == 1 ||!(num % 2))
		return 0;
	srand(time(NULL));
	//for(int i = 0; i < times && num > test[i];i++)
	//	if(!passMullerRabin(num,test[i]))
	//		return 0;
	for(int i = 0;i < times;i++){
		int test = rand() % num;
		if(!passMullerRabin(num,test))
			return 0;
	}
	return 1;
}
class Solution {
public:
    int countPrimes(int n) {
		int count = 0;
        for(int i = 1;i < n;i++){
			if(isPrime(i,20)){
				count++;
			}
		}
		return count;
    }
};
