class Solution {
public:
    int dp[1001][1001];
    int f(string &s, string &t, int i, int j){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = f(s,t,i-1,j-1) + f(s,t,i-1,j);
        }
        return dp[i][j] = f(s,t,i-1,j);
    }
    int numDistinct(string s, string t) {
        int n = s.length()-1;
        int m = t.length()-1;
        memset(dp,-1,sizeof(dp));
        return f(s,t,n,m);
    }
};