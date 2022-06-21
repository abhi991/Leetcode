class Solution {
public:
    int dp[201][1001];
    int solve(vector<vector<int>>&a , int n, int r,int c){
        if(r == n-1) return a[r][c];
        if(dp[r][c] != -1) return dp[r][c];
        int d = a[r][c] + solve(a , n, r+1, c);
        int dia = a[r][c] + solve(a, n, r+1,c+1);
        return dp[r][c] = min(d,dia);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        memset(dp,-1,sizeof(dp));
        return solve(triangle,n,0,0);
    }
};