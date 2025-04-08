class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();
        if(n==1) return str[0];
        sort(str.begin(),str.end());
        string first = str[0];
        string last = str[n-1];
        string s = "";
        for(int i=0;i<(min(first.size(),last.size()));i++){
            if(first[i]==last[i]){
                s += first[i];
            }
            else return s;


        }
        return s;


    }
};