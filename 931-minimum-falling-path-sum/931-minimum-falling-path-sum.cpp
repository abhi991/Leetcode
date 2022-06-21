class Solution {
public:
    int dp[1001][1001];
    int solve(vector<vector<int>>&v, int r, int c){
        if(r < 0 || c < 0 || r >= v.size() || c >= v[0].size()) return INT_MAX-1000;
        if(r==0) {
            return v[r][c];
        }
        
        if(dp[r][c] != -1) return dp[r][c];
        
        int f = v[r][c] + solve(v, r-1,c+1);
        int s = v[r][c] + solve(v, r-1,c);
        int t = v[r][c] + solve(v,r-1,c-1);
        
        return dp[r][c] = min({f,s,t});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        int m = matrix[0].size()-1;
        int ans = INT_MAX;
        memset(dp,-1,sizeof(dp));
        for(int i=m;i>=0;i--){
            ans = min(ans, solve(matrix, n, i));
        }
        return ans;
    }
};