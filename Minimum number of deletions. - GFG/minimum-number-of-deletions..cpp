// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends

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
int minDeletions(string str, int n) {
    return str.length() - longestPalindromeSubseq(str);
} 