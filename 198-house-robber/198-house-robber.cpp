class Solution {
public:
    int rob(vector<int>&nums) {
        vector<int> dp(nums.size()+1, -1);
        dp[0]=0;
        for(int i=1;i <= nums.size() ; i++){
            int incl = nums[i-1] + (i==1 ? 0 : dp[i-2]);
            int excl = dp[i-1];
            dp[i] = max(incl , excl);
        }
        return dp[nums.size()];
    }
};