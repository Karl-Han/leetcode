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
int nums[] = {2,3,5,7};
// base^power % mod
long int FastPowerMod(int mod, long base,long power){
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
// testNum^num
bool passMullerRabin(int num,int testNum,int odd){
	long int x = FastPowerMod(num,testNum,odd);
	if(x == 1 || x == num-1)
		return 1;
	while(odd != num-1){
		x = (x * x) % num;
		odd <<=1;
		if(x == num-1)
			return 1;
	}
	return 0;
}
bool isPrime(int num){
	if(num == 2)
		return 1;
	if(num == 1 ||!(num % 2))
		return 0;
	int odd = (num-1)>>1;
	while(!(odd & 1))
		odd >>=1;
	for(int i = 0;i < 4;i++){
		if(num == nums[i]){
			return 1;
		}
		if(!passMullerRabin(num,nums[i],odd) || num < nums[i])
			return 0;
	}
	return 1;
}
class Solution {
public:
    int countPrimes(int n) {
		int count = 0;
        for(int i = 1;i < n;i++){
			if(isPrime(i)){
				count++;
			}
		}
		return count;
    }
};
