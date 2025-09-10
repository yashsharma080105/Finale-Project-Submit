class Solution {
public:
    vector<int> dp = vector<int>(10000004, -2); // ✅ dp declared once

    int solve(vector<int>& coins , int x){       // ✅ renamed helper to solve
        if(x==0) return 0;
        if(x<0) return INT_MAX;                 // ✅ handle negative
        if(dp[x]!=-2) return dp[x];

        int result  = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int sub = solve(coins , x-coins[i]);
            if(sub != INT_MAX) {
                result = min(result, sub);
            }
        }
        if(result == INT_MAX) return dp[x] = INT_MAX;
        return dp[x] = 1 + result;
    }
    
    int coinChange(vector<int>& coins, int x) {  // ✅ main function renamed
        int ans = solve(coins,x);
        return (ans == INT_MAX) ? -1 : ans;      // ✅ convert impossible to -1
    }
};
