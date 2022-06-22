// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int dp[1001][1001];
    int lcs(string s, string t , int n , int m){
        if(n==0 || m==0)return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(s[n-1] == t[m-1]) {
            return dp[n][m] = 1 + lcs(s,t,n-1,m-1);
        }
        return dp[n][m] = max(lcs(s,t,n-1,m), lcs(s,t,n,m-1));
    }
    int countMin(string str){
        string t = str;
        memset(dp,-1,sizeof(dp));
        reverse(t.begin() , t.end());
        int lenofLCS = lcs(str, t , str.size() , t.size());
        int ros = str.size() - lenofLCS;
        return ros;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends