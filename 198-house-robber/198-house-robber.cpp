class Solution {
public:
    int dp[101];
    int solve(vector<int>&a, int n){
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        int c = solve(a , n-1);
        int b = a[n] + solve(a,n-2);
        return dp[n] = max(c,b);
    }
    int rob(vector<int>& nums){
        memset(dp,-1,sizeof(dp));
        return solve(nums,nums.size()-1);
    }
};