class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>> &v , int r, int c){
        if(r==0 && c==0){
            return v[0][0];
        }
        if(r<0||c<0) return INT_MAX-200;
        if(dp[r][c] != -1) return dp[r][c];
        return dp[r][c] = min(v[r][c] + solve(v, r, c-1),v[r][c] + solve(v, r-1, c));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,n-1,m-1);
    }
};