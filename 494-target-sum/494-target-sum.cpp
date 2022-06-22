class Solution {
public:
    int solve(vector<int> &a , int t, int n , int dp[101][2001] , int s){
        if(n == 0 && s == t) return 1;
        if(n == 0) return 0;
        if(dp[n][s+1000] != -1) return dp[n][s+1000];
        int count=0;
        count += solve(a,t,n-1,dp,s+a[n-1]);
        count += solve(a,t,n-1,dp,s-a[n-1]);
        return dp[n][s+1000] = count;
    }
    int findTargetSumWays(vector<int>& nums, int s) {
        int n = nums.size();
        int sum=0;
        for(auto x:nums) sum+=x;
        if(s > sum || s < -sum) return 0;
        int dp[n+1][sum * 2 + 1];
        memset(dp,0,sizeof(dp));
        dp[0][nums[0]+sum] = 1;
        dp[0][-nums[0]+sum] += 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = -sum; j <= sum; j++) {
                if (dp[i-1][j+sum] != 0) {
                    int tp = nums[i];
                    dp[i][j+sum+tp] += dp[i-1][j+sum];
                    dp[i][j+sum-tp] += dp[i-1][j+sum];
                }
            }
        }
        
        return dp[n-1][s+sum];
    }
};