// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    int dp[101][10001];
    bool f(vector<int>&a, int s ,int n){
        if(s == 0){
            return true;
        }
        if(s < 0) return false;
        if(n < 0) return false;
        
        if(dp[n][s] != -1) return dp[n][s];
        
        bool p = f(a,s-a[n],n-1);
        bool q = f(a,s,n-1);
        
        return dp[n][s] = p||q;
    }
    bool isSubsetSum(vector<int>a, int s){
        memset(dp , -1 , sizeof(dp));
        return f(a,s,a.size()-1);
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