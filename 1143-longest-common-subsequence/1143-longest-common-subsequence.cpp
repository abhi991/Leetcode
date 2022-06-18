class Solution {
public:
    int dp[1001][1001];
    int solve(string &s , string &t , int n , int m){
        
        if(n == 0 || m == 0) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s[n-1] == t[m-1]){
            return dp[n][m] = 1 + solve(s , t,n-1 , m-1);
        }
        else {
            return dp[n][m] = max(solve(s,t,n-1,m) , solve(s,t,n,m-1));
        }
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        memset(dp ,-1, sizeof(dp));
        return solve(text1,text2,n,m);
    }
};