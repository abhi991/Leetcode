class Solution {
public:
    int dp[20][10001];
    int f(vector<int>&a, int n, int s){
        if(s==0) return 0;
        if(n == 0) return INT_MAX-1;
        if(dp[n][s] != -1) return dp[n][s];
        if(s >= a[n-1]){
            return dp[n][s] = min(f(a,n-1,s), 1 + f(a,n,s-a[n-1]));
        }
        return dp[n][s] = f(a, n-1, s);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        int x = f(coins,n,amount);
        return x == INT_MAX-1 ? -1 : x;
    }
};