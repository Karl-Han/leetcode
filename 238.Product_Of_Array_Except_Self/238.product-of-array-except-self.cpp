#include <vector>
/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (52.59%)
 * Total Accepted:    227.6K
 * Total Submissions: 422.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * 
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 * 
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int temp = 1;
		int size = nums.size();
		std::vector<int> A(size,1);
		for(int i = 1;i < size;i++){
			A[i] = A[i-1] * nums[i-1];
		}
		for(int i = size-2;i > -1;i--){
			temp *= nums[i+1];
			A[i] *= temp;
		}
		return A;
    }
};
