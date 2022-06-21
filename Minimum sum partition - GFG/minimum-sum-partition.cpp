// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int a[], int n)  { 
	    int sum=0;
	    for(int i=0;i<n;i++) sum+=a[i];
        vector<vector<int>> dp(1001 , vector<int> (sum+1, 0));
	    
	    for(int i=0;i<=n;i++) dp[i][0]=1;
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(j >= a[i-1]){
	                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
	            }
	            else dp[i][j] = dp[i-1][j];
	        }
	    }
	    
	    int ans = INT_MAX;
	    
	    for(int j=0;j<=sum;j++){
	        if(dp[n][j] == 1){
	            ans = min(ans, abs(j - abs(sum-j)));
	        }
	    }
	    return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends