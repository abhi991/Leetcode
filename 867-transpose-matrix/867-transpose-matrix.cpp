class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& a) {
        vector<vector<int>> vec(a[0].size() , vector<int> (a.size(), 0));
        for(int r=0;r<a.size();r++){
            for(int c = 0; c < a[0].size() ; c++){
                vec[c][r] = a[r][c];
            }
        }
        return vec;
    }
};