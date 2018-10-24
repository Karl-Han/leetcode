/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (38.91%)
 * Total Accepted:    1.1M
 * Total Submissions: 2.9M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		std::bitset<50> bit;
		vector<int> *r = new vector<int>();
		int size = (int)nums.size();
		for(int i = 0;i < size;i++){
			if(bit[target-nums[i]]){
				int j = 0;
				for(;j < i && nums[j] != (target-nums[i]);j++);
				r->push_back(j);
				r->push_back(i);
				return *r;
			}
			else 
				bit.set(nums[i]);
		}
		//for(int i = 0;i < size;i++){
		//	if(bit[target-nums[i]]){
		//		int j = 0;
		//		for(;j < i && nums[j] == target-nums[i];j++)
		//			r->push_back(j);
		//		r->push_back(i);
		//		return *r;
		//	}
		//}
    }
};
