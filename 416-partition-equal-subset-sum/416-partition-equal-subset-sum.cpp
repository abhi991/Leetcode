class Solution {
public:
    bool solve(vector<int>a, int tar , int i ,vector<vector<int>> &dp){
        if(tar == 0) return true;
        if(i >= a.size() || tar < 0) return false;
        
        if(dp[i][tar] != -1) return dp[i][tar];
        
        return dp[i][tar] = solve(a,tar-a[i],i+1,dp) || solve(a,tar,i+1,dp);
    }
    bool canPartition(vector<int>&a) {
        int sum=0 , n = a.size();
        for(int i=0;i<a.size();i++){
            sum+=a[i];
        }
        if(sum&1)return false;
        vector<vector<int>> dp(n+1, vector<int> (sum+1 ,-1));
        return solve(a,sum/2,0,dp);
    }
};