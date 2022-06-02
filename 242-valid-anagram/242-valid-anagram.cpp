class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>v(26,0);
        for(int i=0;i<s.length();i++){
            v[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            v[t[i]-'a']--;
        }
        for(auto x:v){
            if(x!=0) return false;
        }
        return true;
    }
};