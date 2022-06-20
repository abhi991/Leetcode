class Solution {
public:
    int dp[1001][1001];
    int lcs(string &s, string &t, int n , int m){
        if(n==0 || m==0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s[n-1] == t[m-1]) return dp[n][m] = 1+lcs(s,t,n-1,m-1);
        
        return dp[n][m] = max(lcs(s,t, n-1,m) , lcs(s,t,n,m-1));
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        string t = s;
        reverse(t.begin() , t.end());
        string ans="";
        return lcs(s, t, n , n);
    }
};