class Solution {
public:
    int solve(vector<int> a , int n , bool isAdjacent , vector<int> &dp){
        if(n <= 0) return 0;
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = max((a[n-1] + solve(a , n-2 , true,dp)) ,solve(a , n-1 , false ,dp));
    }
    int rob(vector<int>&nums) {
        vector<int> dp(nums.size()+1, -1);
        return solve(nums, nums.size() , false , dp);
    }
};