class Solution {
public:
    int helper(vector<int> &a , int amount , int n , int dp[][10001]){
        if(amount == 0) return 1;
        if(n == 0 || amount < 0) return 0;
        if(dp[n][amount] != -1) return dp[n][amount];
        return dp[n][amount] = helper(a, amount-a[n-1] , n,dp) + helper(a, amount , n-1,dp);
    }
    int change(int amount, vector<int>& coins) {
        int dp[coins.size()+1][10001];
        memset(dp , -1 , sizeof(dp));
        return helper(coins, amount,coins.size(),dp);
    }
};