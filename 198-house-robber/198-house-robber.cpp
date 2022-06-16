class Solution {
public:
//     int solve(vector<int> a , int n , vector<int> &dp){
//         if(n <= 0) return 0;
//         if(dp[n] != -1) return dp[n];
        
//         int incl = a[n-1] + solve(a , n-2 ,dp);
//         int excl = solve(a , n-1 ,dp);
//         return dp[n] = max(incl ,excl);
//     }
    int rob(vector<int>&nums) {
        vector<int> dp(nums.size()+1, -1);
        dp[0]=0;
        for(int i=1;i <= nums.size() ; i++){
            int incl = nums[i-1] + (i==1 ? dp[i-1] : dp[i-2]);
            int excl = dp[i-1];
            dp[i] = max(incl , excl);
        }
        return dp[nums.size()];
    }
};