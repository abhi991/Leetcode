class Solution {
public:
    int dp[501][501];
    int lcs(string &s, string &t, int n , int m){
        if(n==0 || m==0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s[n-1] == t[m-1]) return dp[n][m] = 1+lcs(s,t,n-1,m-1);
        
        return dp[n][m] = max(lcs(s,t, n-1,m) , lcs(s,t,n,m-1));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        memset(dp,-1,sizeof(dp));
        return n+m - 2*lcs(word1,word2,n,m);
    }
};