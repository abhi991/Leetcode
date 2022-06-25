class Solution {
public:
    int maxProfit(vector<int>&a) {
        int minSell = a[0] ,ans=0;
        for(int i=1;i<a.size();i++){
            if(a[i] < minSell){
                minSell = a[i];
            }
            else{
                ans = max(ans , a[i] - minSell);
            }
        }
        return ans;
    }
};