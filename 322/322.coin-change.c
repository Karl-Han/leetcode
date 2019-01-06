/*
 * @lc app=leetcode id=322 lang=c
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (27.82%)
 * Total Accepted:    137.2K
 * Total Submissions: 493.4K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */
int min(int a,int b){
	return a > b?b:a;
}
int coinChange(int* coins, int coinsSize, int amount) {
    int count[amount];
	memset(count,-1,amount);
	int minCoin = 1<<29;
	for(int i = 0;i < coinsSize;i++){
		int coin = coins[i];
		if(coin < minCoin)
			minCoin = coin;
		count[coin] = 1;
	}
	for(int j = minCoin;j < amount;j++){
		for(int m = 0;m < coinsSize;m++){
			if(count[j-coins[m]] == -1)
				return -1;
			if(j < coins[m])
				break;
			count[j] = min(count[j],1+count[j-coins[m]]);
		}
		printf("count[%d] = %d",j,count[j]);
	}
	if(count[amount-1] > (1<<29))
		return -1;
	return count[amount-1];
}
