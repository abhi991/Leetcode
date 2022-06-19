// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends

class Solution{
    public:
    int firstNonRepeating(int a[], int n) { 
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp[a[i]] == 1) return a[i];
        }
        return ans;
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
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.firstNonRepeating(arr,n)<<endl;
    }
}
  // } Driver Code Ends