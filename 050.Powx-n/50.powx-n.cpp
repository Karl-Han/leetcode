/*
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (26.63%)
 * Total Accepted:    252.3K
 * Total Submissions: 944.7K
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (xn).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2-2 = 1/22 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−231, 231 − 1]
 * 
 * 
 */
class Solution {
public:
	double FastPow(double x,long n){
		if(n == 1)
			return x;
		if(n & 1)
			return x * FastPow(x*x,n/2);
		return FastPow(x*x,n/2);
	}
    double myPow(double x, int n) {
		if(n == 0 || x == 1.0)
			return 1;
		long bigger = n;
		if(n < 0){
			x = 1 / x;
			bigger = -bigger;
		}
        return FastPow(x,bigger);
    }
};
