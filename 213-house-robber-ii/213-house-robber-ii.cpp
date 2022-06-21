class Solution {
public:
    int dp[101];
    int solve(vector<int> &a, int n){
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        int c = solve(a , n-1);
        int b = a[n] + solve(a,n-2);
        return dp[n] = max(c,b);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        memset(dp,-1,sizeof(dp));
        vector <int> tp1, tp2;
        for(int i=0;i<n;i++){
            if( i != 0) tp1.push_back(nums[i]);
            if( i != n-1) tp2.push_back(nums[i]);
        }
        int wf = solve(tp1, tp1.size()-1);
        memset(dp,-1,sizeof(dp));
        int wl = solve(tp2, tp2.size()-1);
        
        return max(wf,wl);
    }
};