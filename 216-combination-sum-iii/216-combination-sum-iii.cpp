class Solution {
public:
    void solve(vector<vector<int>> &ans , vector<int> &v , int k , int n, int i){
        if(i >= 11 || n < 0) return;
        if(n==0 && v.size() == k){
            ans.push_back(v);
            return;
        }
        v.push_back(i);
        cout << i << " ";
        solve(ans, v , k , n-i , i+1);
        cout << n << endl;
        v.pop_back();
        solve(ans, v , k , n , i+1);   
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        vector<vector<int>> ans;
        solve(ans,v,k,n,1);
        return ans;
    }
};