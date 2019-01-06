/*
 * @lc app=leetcode id=746 lang=c
 *
 * [746] Min Cost Climbing Stairs
 *
 * https://leetcode.com/problems/min-cost-climbing-stairs/description/
 *
 * algorithms
 * Easy (44.58%)
 * Total Accepted:    52.9K
 * Total Submissions: 118.6K
 * Testcase Example:  '[0,0,0,0]'
 *
 * 
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0
 * indexed).
 * 
 * Once you pay the cost, you can either climb one or two steps. You need to
 * find minimum cost to reach the top of the floor, and you can either start
 * from the step with index 0, or the step with index 1.
 * 
 * 
 * Example 1:
 * 
 * Input: cost = [10, 15, 20]
 * Output: 15
 * Explanation: Cheapest is start on cost[1], pay that cost and go to the
 * top.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 * Output: 6
 * Explanation: Cheapest is start on cost[0], and only step on 1s, skipping
 * cost[3].
 * 
 * 
 * 
 * Note:
 * 
 * cost will have a length in the range [2, 1000].
 * Every cost[i] will be an integer in the range [0, 999].
 * 
 * 
 */
int min(int a,int b){
	return a < b?a:b;
}
int minCostClimbingStairs(int* cost, int costSize) {
    int store[costSize+1];
	memset(store,0,costSize+1);
	store[0] = cost[0];
	store[1] = cost[1];
	/*
	if(costSize == 3){
		store[3] = min(cost[1],cost[2]);
		return store[3];
	}
	store[2] = store[1] = min(cost[0],cost[1]);
	//store[2] = min(cost[0],cost[1] + store[0]);
	for(int i = 3;i <= costSize;i++){
		//store[i] = min(cost[i-1] + store[i-2],cost[i-2] + store[i-3]);
		store[i] = min(store[i-1] + cost[i-2],store[i-2] + cost[i-3]);
		printf("%d = %d\n",i-1,store[i]);
	}
	printf("costSize = %d\n res = %d",costSize-1,store[costSize]);
	return store[costSize];
}
