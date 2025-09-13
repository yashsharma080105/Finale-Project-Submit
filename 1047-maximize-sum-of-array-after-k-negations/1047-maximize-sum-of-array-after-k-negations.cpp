class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> pq(nums.begin(),nums.end()); 
        int sum =0;
        for(int i=0;i<nums.size();i++) sum += nums[i];
        while(k--){
            int el = pq.top(); // min ele
            if(el ==0){
                break;
            }
            pq.pop();  // remove the smallest
            sum -= el;
            pq.push(-1*el); // add the negative number
            sum +=  (-el);
        }
        return sum;

    }
};