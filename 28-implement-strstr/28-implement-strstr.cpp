class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() > haystack.length()) return -1;
        int nl = needle.length();
        for(int i=0;i<=haystack.length()-nl;i++){
            if(haystack.substr(i , nl) == needle) return i;
        }
        return -1;
    }
};