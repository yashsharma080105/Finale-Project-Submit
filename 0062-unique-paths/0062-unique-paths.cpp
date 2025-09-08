class Solution {
public:
    int helper(int sr, int sc, int er, int ec,vector<vector<int>>& dp){
        if(sr==er && sc==ec) return 1;
        if(sr>er || sc>ec) return 0;
        if(dp[sr][sc]!=-1) return dp[sr][sc];
        int rightways = helper(sr,sc+1,er,ec,dp);
        int downways  = helper(sr+1,sc,er,ec,dp);
        
        return dp[sr][sc] = rightways + downways;
    }


    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));  // 2d dp
        return helper(0,0,m-1,n-1,dp);
        
    }
};