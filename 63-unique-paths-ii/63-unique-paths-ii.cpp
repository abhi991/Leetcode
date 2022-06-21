class Solution {
public:
    int dp[101][101];
    int f(vector<vector<int>> v, int n , int m){
        if(n<0||m<0||v[n][m]==1) return 0;
        if(n==0 && m==0) return 1;
        if(dp[n][m] != -1) return dp[n][m];
        return dp[n][m] = f(v,n-1,m) + f(v,n,m-1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>&v) {
        memset(dp,-1,sizeof(dp));
        int n = v.size();
        int m = v[0].size();
        return f(v,n-1,m-1);
    }
};