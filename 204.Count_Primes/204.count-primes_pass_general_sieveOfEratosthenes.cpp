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
class Solution {
public:
    int countPrimes(int n) {
		if(n == 0 || n == 1)
			return 0;
		bitset<1500000> arr;
		int count = 0;
		for(int i = 2;i < n;i++){
			if(!arr[i]){
				count++;
				for(long long int j = i;j > 0 && j < n;j += i){
					arr[j] = 1;
				}
			}
		}
		return count;
    }
};
