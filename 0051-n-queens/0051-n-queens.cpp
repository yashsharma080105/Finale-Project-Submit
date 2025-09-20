class Solution {
public:
    vector<vector<char>> grid;
    vector<vector<string>> result;

    bool canPlacequeen(int row, int col,int n){
        // column check
        for(int i = row-1; i>=0; i--){
            if(grid[i][col] == 'Q') 
                return false;
        }
        // left diag check
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(grid[i][j] == 'Q') return false;
        }
        // right diag check
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(grid[i][j] == 'Q') return false;
        }
        return true;   // safe to place queen
    }

    void f(int row, int n){
        if(row==n){   // base case
            vector<string> temp;
            for(int i=0; i<n; i++){
                string res = "";
                for(int j=0; j<n; j++){
                    res += grid[i][j];
                }
                temp.push_back(res);
            }
            result.push_back(temp);
            return;
        }

        for(int col=0; col<n; col++){
            if(canPlacequeen(row,col,n)){
                grid[row][col] = 'Q';
                f(row+1,n);
                grid[row][col] = '.';    // backtracking
            }
        }
    }

    vector<vector<string>> solveNQueens(int n){
        grid.assign(n, vector<char>(n, '.'));  // clear + initialize
        result.clear();                        // clear old results
        f(0,n);
        return result;
    }
};
