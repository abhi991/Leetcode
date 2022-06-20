// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    int dp[1001][1001];
	    int solve(string &s , string &t , int n , int m){
        
        if(n == 0 || m == 0) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s[n-1] == t[m-1] && n -1 != m-1){
            return dp[n][m] = 1 + solve(s , t,n-1 , m-1);
        }
        else {
            return dp[n][m] = max(solve(s,t,n-1,m) , solve(s,t,n,m-1));
        }
        }
		int LongestRepeatingSubsequence(string str){
		    memset(dp,-1,sizeof(dp));
		    return solve(str, str, str.size() ,str.size());
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends