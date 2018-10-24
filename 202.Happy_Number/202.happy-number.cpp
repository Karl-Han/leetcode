/*
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (42.89%)
 * Total Accepted:    187.4K
 * Total Submissions: 436.5K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 * 
 */
class Solution {
public:
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
};
