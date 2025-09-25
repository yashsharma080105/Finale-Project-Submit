class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        unordered_map<int,int> mp;
        for(auto i :nums){
            mp[i]++;
        }
        for(auto a : mp){
            if(a.second==1) result.push_back(a.first);
        }
        return result;
        
    }
};