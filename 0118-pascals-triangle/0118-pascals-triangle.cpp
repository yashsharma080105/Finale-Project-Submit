class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);  // Create a vector of vectors with size numRows
        for (int i = 0; i < numRows; ++i) {
            v[i].resize(i + 1);  // Resize each row to have (i + 1) elements
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    v[i][j] = 1;  // First and last elements in the row are 1
                } else {
                    v[i][j] = v[i - 1][j - 1] + v[i - 1][j];  // Sum of the two elements above
                }
            }
        }
        return v;
    }
};