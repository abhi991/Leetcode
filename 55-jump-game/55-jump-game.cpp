class Solution {
    vector<int> dp;
    int solve(int idx, vector<int> &nums){
        if(idx == nums.size() - 1) return true;
        if(dp[idx] != -1) return dp[idx];
        
        for(int i = 1; i <= nums[idx]; i++){
            if((idx + i < nums.size()) && (solve(idx + i, nums))){
                return dp[idx] = true;
            }
        }
        
        return dp[idx] = false;
    }
public:
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        dp[n - 1] = true;
        
        return solve(0, nums);
    }
};