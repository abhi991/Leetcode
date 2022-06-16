// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    // Solution(){
    //     memset(dp , -1 , sizeof(dp));
    // }
    // bool isSubsetSum(vector<int>a, int sum ,int i=0){
        
    //     if(sum==0) return true;
    //     if(sum < 0) return false;
    //     if(i == a.size()) return false;
        
    //     if(dp[i][sum] != -1) return dp[i][sum];
        
    //     bool m = isSubsetSum(a, sum - a[i] , i+1);
    //     bool n = isSubsetSum(a, sum , i+1);
    //     return dp[i][sum] = m||n;
    // }
    bool isSubsetSum(vector<int> a, int sum){
        int dp[101][10001];
        for(int i=0;i<=a.size();i++) dp[i][0] = 1;
        for(int i=1;i<=sum;i++) dp[0][i] = 0;
        
        for(int i=1;i<=a.size();i++){
            for(int j=1;j<=sum;j++){
                if(j >= a[i-1]){
                    dp[i][j] = dp[i-1][j - a[i-1]] || dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[a.size()][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends