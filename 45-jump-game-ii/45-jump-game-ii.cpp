class Solution {
public:
    int dp[10001];
    int minNumberWays(vector <int> &arr, long long currentIndex){
        if(currentIndex >= arr.size()-1) return 0;
        if(dp[currentIndex] != -1) return dp[currentIndex];
        long long tmp = 1e8;
        
        for(int i=1; i <= arr[currentIndex] ;i++){
            long long c1 =  1 + minNumberWays(arr, currentIndex + i);
            tmp = min(tmp,c1);
        }
        
        return dp[currentIndex] = tmp;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return minNumberWays(nums,0);
    }
};