class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int  m = arr.size();
        int n = arr[0].size();
        if(arr[0][0] ==1 || arr[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m,vector<int> (n,0));

        // starting cell
        dp[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1) {
                    dp[i][j] = 0;   //obstacle -> no path
                }
                else{
                    if(i>0) dp[i][j] += dp[i-1][j]; 
                    if(j>0) dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};