class Solution {
public:
    vector<int> dp;

    int f(vector<int> arr, int i){
        if(i == arr.size()-1) return arr[i];  // single house 
        if( i == arr.size()-2) return max(arr[i],arr[i+1]);  // 2 house
        if(dp[i] != -1) return dp[i]; // ith state already computed

    // if dp[i] was - 1 so lets computed ith state for the first
        return  dp[i] = max(arr[i] + f(arr,i+2), 0+ f(arr,i+1));
    }

    int rob(vector<int>& nums) {
        dp.resize(105,-1);     // just take a large value in replace of nums.size(
        return f(nums,0);
        
        
    }
};