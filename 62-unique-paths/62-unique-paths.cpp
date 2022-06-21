class Solution {
public:
    // int uniquePathsMEM(int r, int c) {
    //     if(r == 1 || c == 1) return 1;
    //     if(dp[r][c] != -1) return dp[r][c];
    //     return dp[r][c] = uniquePaths(r-1,c) + uniquePaths(r,c-1);
    // }
    int uniquePaths(int r, int c){
        vector<vector<int>> dp(r+1 , vector<int>(c+1,0));
        for(int i=1;i<=r;i++){
            dp[i][1] = 1;
        }
        for(int i=1;i<=c;i++){
            dp[1][i] = 1;
        }
        for(int i=2;i<=r;i++){
            for(int j=2;j<=c;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[r][c];
    }
};