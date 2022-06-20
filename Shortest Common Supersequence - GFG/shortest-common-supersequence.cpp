// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    int dp[1001][1001];
    int lcs(string s, string t, int n, int m){
        if(n==0 || m==0) return 0;
        if(dp[n][m]  != -1) return dp[n][m];
        
        if(s[n-1] == t[m-1]) return dp[n][m] = 1+lcs(s,t,n-1,m-1);
        
        return dp[n][m] = max(lcs(s ,t , n-1 , m) , lcs(s ,t, n, m-1));
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n){
        memset(dp,-1,sizeof(dp));
        return n+m-lcs(X,Y,m,n);
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends