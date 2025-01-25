class Solution {
public:
    int strStr(string haystack, string needle) {
        int s = haystack.length();
        int t = needle.length();
        if(s<t){
            return -1;
        }
        for(int i=0;i<=s-t;i++){
            if(haystack.substr(i,t) == needle){
                return i;
            }
        }return -1;
    }
};