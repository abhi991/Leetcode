// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int dp[1001][1001];
    int lcs(string &s, string &t, int n , int m){
        if(n==0 || m==0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s[n-1] == t[m-1]) return dp[n][m] = 1+lcs(s,t,n-1,m-1);
        
        return dp[n][m] = max(lcs(s,t, n-1,m) , lcs(s,t,n,m-1));
    }
	int minOperations(string str1, string str2) {
	    memset(dp,-1,sizeof(dp));
	    int lcsq = lcs(str1 , str2 , str1.size() , str2.size());
	    int del = str1.size() - lcsq;
	    int ins = abs(str2.size() - lcsq);
	    return del+ins;
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends