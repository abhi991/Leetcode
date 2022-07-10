class Solution {
public:
    int dp[1001];
    int solve(vector<int>&a , int n , int i){
        if(i==n || i == n-1) return 0;
        if(i>n) return 1e8;
        if(dp[i] != -1) return dp[i];
        int s1 = a[i] + solve(a, n, i+1);
        int s2 = a[i+1] + solve(a, n, i+2);
        return dp[i] = min(s1,s2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return solve(cost,cost.size(),0);
    }
};