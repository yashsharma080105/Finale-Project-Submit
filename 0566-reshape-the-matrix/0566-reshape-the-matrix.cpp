class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        int totalElement = m*n;

        if(totalElement!= r*c){
            return mat;
        }

        vector<vector<int>> reshape(r, vector<int>(c));
        for(int i=0;i<totalElement;i++){
            reshape[i/c][i%c] = mat[i/n][i%n];

        }
        return reshape;
    }
};