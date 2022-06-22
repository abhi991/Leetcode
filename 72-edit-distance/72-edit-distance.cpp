class Solution {
public:
    int dp[1001][1001];
    int f(string &s,string &t,int n,int m){
        if(n < 0) return m+1; //min insertion ops
        if(m < 0) return n+1; //min deletion ops
        if(dp[n][m] != -1)return dp[n][m];
        if(s[n] == t[m]){
            return dp[n][m] = f(s,t,n-1,m-1);
        }
        int a = 1+f(s,t,n-1,m); //deletion
        int b = 1+f(s,t,n-1,m-1); //replace
        int c = 1+f(s,t,n,m-1); //insertion
        return dp[n][m] = min({a,b,c});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size()-1;
        int m = word2.size()-1;
        memset(dp,-1,sizeof(dp));
        return f(word1,word2,n,m);
    }
};