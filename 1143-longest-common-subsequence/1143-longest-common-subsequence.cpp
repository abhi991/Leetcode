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
        vector <int> prev(m+1,0) , cur(m+1,0);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    cur[j] = 1 + prev[j-1];
                }
                else cur[j] = max(prev[j] , cur[j-1]);
            }
            prev=cur;
        }
        
        return prev[m];
    }
};