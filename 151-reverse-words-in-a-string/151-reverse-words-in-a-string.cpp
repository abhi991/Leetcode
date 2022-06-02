class Solution {
public:
    void extractWords(string s , stack <string> &st){
        string word = "";
        for(int i=0;i<s.length();i++){
            if(s[i] == ' ' && word.length() >= 1){
                st.push(word);
                word="";
            }
            if(s[i] != ' ') word += s[i];
        }
        st.push(word);
    }
    string reverseWords(string s) {
        stack <string> st;
        extractWords(s, st);
        string ans="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(st.size() >= 1 && ans.size() >= 1){
                ans += " ";
            }
        }
        return ans;
    }
};