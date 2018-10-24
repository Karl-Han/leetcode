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
		sort(nums.begin(),nums.end());
		//int size = nums.size();
		//int begin = (0 + size)/2;
		//int end = begin+1;
		int end = nums.size()-1;
		while(nums[end] > target)
			end--;
		int finalNum = end;
		end = end / 2 + 1;
		int begin = end -1;
		vector<int> *r = new vector<int>();
        while(1){
			if((nums[begin] + nums[end]) == target){
				//if(begin != end){
					r->push_back(begin);
					r->push_back(end);
					return *r;
				//}
				//else {
				//	if(nums[begin-1] + nums[begin] == target){
				//		r->push_back(begin-1);
				//		r->push_back(end);
				//		return *r;
				//	}
				//	else if(nums[begin] + nums[begin+1] == target){
				//		r->push_back(begin);
				//		r->push_back(end);
				//		return *r;
				//	}
				//	begin = begin -1;
				//	end = end +1;
				//	continue;
				//}
			}
			if((nums[begin] + nums[end]) < target){
				end++;
				continue;
			}
			else {
				begin--;
				continue;
			}
		}
		return *r;
    }
};
