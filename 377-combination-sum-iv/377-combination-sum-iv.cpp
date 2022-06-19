class Solution {
public:
    int dp[1001];
    int solve(vector<int>&nums , int target){
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(dp[target] != -1) return dp[target];
        int total=0;
        for(int i=1;i<=nums.size();i++){
            total += solve(nums , target - nums[i-1]);
        }
        return dp[target] = total;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp , -1 ,sizeof(dp));
        return solve(nums,target);
    }
};