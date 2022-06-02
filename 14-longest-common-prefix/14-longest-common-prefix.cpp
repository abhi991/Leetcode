class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(int i=1; i<strs.size();i++){
            int j=0,k=0;
            string temp = strs[i];
            prefix = prefix.substr(0 , min(prefix.length() , temp.length()));
            while(j < temp.size() && k < prefix.length()){
                if(prefix[k] != temp[j]){
                    prefix = prefix.substr(0,j);
                    break;
                }
                j++;
                k++;
            }
        }
        return prefix;
    }
};