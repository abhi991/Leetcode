class Solution {
public:
    vector<vector<int>> dp{101 , vector<int>(101,-1)};
    int uniquePaths(int r, int c) {
        if(r == 1 || c == 1) return 1;
        if(dp[r][c] != -1) return dp[r][c];
        return dp[r][c] = uniquePaths(r-1,c) + uniquePaths(r,c-1);
    }
};