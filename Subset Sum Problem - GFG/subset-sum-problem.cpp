// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{
private:
    int dp[101][10000];
public:
    Solution(){
        memset(dp , -1 , sizeof(dp));
    }
    bool isSubsetSum(vector<int>a, int sum ,int i=0){
        
        if(sum==0) return true;
        if(sum < 0) return false;
        if(i == a.size()) return false;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        bool m = isSubsetSum(a, sum - a[i] , i+1);
        bool n = isSubsetSum(a, sum , i+1);
        
        return dp[i][sum] = m||n;
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