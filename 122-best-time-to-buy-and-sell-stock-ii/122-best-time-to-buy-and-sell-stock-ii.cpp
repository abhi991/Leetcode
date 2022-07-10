class Solution {
public:
    int dp[2][30001];
    int f(vector<int>&a , int n , int b,int i){
        if(i == n) return 0;
        if(dp[b][i] != -1) return dp[b][i];
        int profit = 0;
        
        if(b){
            int buy = -a[i] + f(a, n, 0,i+1);
            int dontB = 0 + f(a , n, 1,i+1);
            profit = max(buy,dontB);
        }
        else{
            int sell = a[i] + f(a, n, 1,i+1);
            int dontS = 0 + f(a,n,0,i+1);
            profit = max(sell ,dontS);
        }
        
        return dp[b][i]=profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp , -1, sizeof(dp));
        return f(prices,prices.size(),1,0);
    }
};