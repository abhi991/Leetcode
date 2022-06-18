// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  private:
    int dp[1001];
  public:
  Solution(){
      memset(dp , -1 , sizeof(dp));
  }
    int cutRod(int p[], int n) {
        if(n==0) return 0;
        if(dp[n] != -1) return dp[n];
        int q = -1;
        for(int i=1;i<=n;i++){
            q = max(q, p[i-1] + cutRod(p,n-i));
        }
        return dp[n] = q;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends