// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int ans=0;
    int dp[1001][1001];
    int longestCommonSubst(string &s, string &t, int n, int m , int &ans){
        int take=0;
        if(n == 0 || m == 0) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s[n-1] == t[m-1]){
            take = 1 + longestCommonSubst(s,t,n-1,m-1 , ans);
        }
        int tp1 = longestCommonSubst(s,t,n-1,m,ans);
        int tp2 = longestCommonSubst(s,t,n,m-1,ans);
        ans = max(ans , take);
        return dp[n][m] = take;
    }
    int longestCommonSubstr (string s, string t, int n, int m){
        memset(dp,-1,sizeof(dp));
        int ans=0;
        longestCommonSubst(s,t,n,m ,ans);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends