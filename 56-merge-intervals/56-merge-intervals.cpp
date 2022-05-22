class Solution
{
    public:
        vector<vector < int>> merge(vector<vector < int>> &stockPrices)
        {
            if (stockPrices.size() <= 1) return stockPrices;
            sort(stockPrices.begin(), stockPrices.end());
            vector<vector < int>> ans;
            ans.push_back(stockPrices[0]);
            for (int i = 1; i < stockPrices.size(); i++)
            {
                if (ans.back()[1] >= stockPrices[i][0]) ans.back()[1] = max(ans.back()[1], stockPrices[i][1]);
                else ans.push_back(stockPrices[i]);
            }
            return ans;
        }
};