// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    private:
        int dp[1000001];
  public:
  Solution(){
      memset(dp,-1,sizeof(dp));
  }
    int minOperation(int n){
        if(n==0) return 0;
        if(dp[n] != -1) return dp[n];
        
        if(n%2==0){
            return dp[n] = min(minOperation(n-1)+1 , minOperation(n/2)+1);
        }
        
        return dp[n] =minOperation(n-1)+1;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends