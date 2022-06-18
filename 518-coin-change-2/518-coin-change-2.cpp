class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector <int> prev(amount+1 , 0) , cur(amount+1, 0);

        cur[0]=1;
        
        for(int i=0;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(j >= coins[i]){
                    cur[j] = cur[j-coins[i]] + prev[j];
                }
            }
            prev = cur;
        }
        
        return prev[amount];
    }
};