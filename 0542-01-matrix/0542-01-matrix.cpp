class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                }
                else{
                    mat[i][j] = INT_MAX;
                }
            }
        }

        while(!q.empty()){
            auto cell = q.front();
            q.pop();
            int row = cell.first;
            int col = cell.second;

            for(int d =0;d<4;d++){
                int newRow = row+dir[d][0];
                int newCol = col+dir[d][1];

                if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && mat[newRow][newCol] > mat[row][col] + 1){
                    mat[newRow][newCol] = mat[row][col] +1;
                    q.push({newRow,newCol});
                }
            }
        }
        return mat;

        
    }
};