class Solution {
public:
    int dp[100001];
    bool solve(vector <int> &nums, int n, int jmp){
        if(jmp > n) return false;
        if(jmp == n) {
            return true;
        }
        
        if(dp[jmp-1] != -1) return dp[jmp-1];
        
        int ans = false;
        
        for(int i=1;i<=nums[jmp-1];i++){
            if(dp[jmp-1] != -1) return dp[jmp-1]; 
            int can = solve(nums , n, jmp + i);
            ans = (can || ans);
            if(ans==true) return dp[jmp-1]=ans;
        }
        
        return dp[jmp-1] = ans;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,n,1);
    }
};