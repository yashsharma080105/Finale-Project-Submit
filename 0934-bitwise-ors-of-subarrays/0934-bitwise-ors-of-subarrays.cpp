class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        unordered_set<int> cur;
        
        for (int num : arr) {
            unordered_set<int> next;
            next.insert(num); // subarray with single element

            for (int x : cur) {
                next.insert(x | num); // extend previous subarrays
            }

            cur = next;

            for (int x : cur) {
                res.insert(x); // add all to final result
            }
        }

        return res.size(); // number of unique ORs
    }
};
