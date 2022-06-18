class Solution {
public:
    int dp[10001];
    int coinChang(vector<int>& coins, int s){
        if(s == 0) return 0;
        int ans = INT_MAX-1;
        if(dp[s] != -1) return dp[s];
        
        for(int i=1;i<=coins.size();i++){
            if(s >= coins[i-1]){
                ans = min(ans, 1 + coinChang(coins, s - coins[i-1]));
                dp[s] = ans;
            }
        }
        
        return (ans == INT_MAX ? INT_MAX-1 : ans);
    }
    int coinChange(vector<int>& coins, int s) {
        memset (dp , -1 , sizeof(dp));
        int x = coinChang(coins,s);
        return (x == INT_MAX-1 ? -1 : x);
    }
};