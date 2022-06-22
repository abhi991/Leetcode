class Solution {
public:
    int solve(vector<int> &a , int t, int n , int dp[101][2001] , int s){
        
        if(n == 0 && s == t) return 1;
        if(n == 0) return 0;
        if(dp[n][s+1000] != -1) return dp[n][s+1000];
        int add = solve(a,t,n-1,dp,s+a[n-1]);
        int sub = solve(a,t,n-1,dp,s-a[n-1]);
        return dp[n][s+1000] = add+sub;
    
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int dp[101][2001];
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        return solve(nums,target,n,dp,0);
    }
};