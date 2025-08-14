class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int count = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] == val) continue;
            else {
                ans.push_back(nums[i]);
                count++;
            }
        }
        // Copy ans back to nums
        for (int i = 0; i < count; i++) {
            nums[i] = ans[i];
        }
        return count;
    }
};
