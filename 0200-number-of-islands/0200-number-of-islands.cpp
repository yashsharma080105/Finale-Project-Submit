class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] != '1'){
            return;
        }
        grid[i][j] = '0' ;   //mark as visited
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    
               
        
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int row  = grid.size();
        int col =  grid[0].size();

        int cc = 0;  // store the numbers of connected components
        for(int r=0;r<row;r++){
            for(int c =0;c<col;c++){
                if(grid[r][c] == '1'){
                    cc++;
                    dfs(grid,r,c);
                }
            }
        }return cc;
    }

    
};