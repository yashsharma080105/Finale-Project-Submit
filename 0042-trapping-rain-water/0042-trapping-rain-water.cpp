#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0; // edge case: empty array

        // Step 1: Create two arrays
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        // Step 2: Fill leftMax
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            // maximum up to current index from the left
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Step 3: Fill rightMax
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            // maximum up to current index from the right
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        // Step 4: Calculate trapped water
        int water = 0;
        for (int i = 0; i < n; i++) {
            // Water at index i = min(leftMax[i], rightMax[i]) - height[i]
            int trapped = min(leftMax[i], rightMax[i]) - height[i];
            if (trapped > 0) { // only add if positive
                water += trapped;
            }
        }

        return water;
    }
};
