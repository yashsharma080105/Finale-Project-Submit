class Solution {
public:
    
        // T.C = O(n)  S.c O(1)
    int rob(vector<int>& nums) {
        int maxRob  = 0;   // dp[i-1]
        int prevRob = 0;   // dp[i-2]
        for(auto currvalue : nums){
            int temp = max(maxRob,prevRob+currvalue);
            prevRob = maxRob;
            maxRob = temp;


        }
        return maxRob;

       
        
        
    }
};