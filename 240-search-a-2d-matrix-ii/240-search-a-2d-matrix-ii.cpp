class Solution {
public:
    bool searchMatrix(vector<vector<int>>& vec, int target) {
        
        int m=vec.size();
        int n=vec[0].size();
        int i=0,j=n-1;
        while(i<m&&j>=0)
        {
            if(vec[i][j]==target)
                return true;
            else
            {
                if(target>vec[i][j])
                    i++;
                else
                    j--;
            }
        }
        return false;
    }
};