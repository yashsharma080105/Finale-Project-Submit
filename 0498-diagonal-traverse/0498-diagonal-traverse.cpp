class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool up =true;
        int m = mat.size();
        int n = mat[0].size();
        int row =0;
        int col = 0;
        vector<int> ans;
        while(row<m && col<n){
            if(up){
                ans.push_back(mat[row][col]);
                col +=1;
                row -= 1;
                if(col ==n){
                    row +=2;
                    col -=1;
                    up = false;
                }
                else if(row<0){
                    row +=1;
                    up = false;
                }
            }else{
                ans.push_back(mat[row][col]);
                col -=1;
                row+=1;
                if(row == m){
                    col +=2;
                    row -=1;
                    up = true;
            }
            else if(col<0){
                col +=1;
                up = true;
            }}
        }return ans;

    }
};