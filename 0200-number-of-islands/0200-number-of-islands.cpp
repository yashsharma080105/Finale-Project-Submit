class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row  = grid.size();
        int col =  grid[0].size();

        int cc = 0;  // store the numbers of connected components
        for(int r=0;r<row;r++){
            for(int c =0;c<col;c++){
                if(grid[r][c] == '0'){
                    // it is a water body
                    continue;
                }
                
                // new univisted land piece found i.e new connected component
                cc++;
                grid[r][c] = '0' ; // mark it visited
                queue<pair<int,int>> qu;
                qu.push({r,c});  // store the src node
                while(not qu.empty()){
                    auto curr = qu.front();  // get one node from queue
                    qu.pop();
                    // go to all unvisited neighbour of the curr node
                    int currRow = curr.first;
                    int currCol = curr.second;
                    // check up
                    if(currRow-1 >=0 and grid[currRow-1][currCol]=='1'){
                        qu.push({currRow-1,currCol});
                        grid[currRow-1][currCol] = '0';
                    }
                    //check down
                    if(currRow+1 < row and grid[currRow+1][currCol] == '1'){
                        qu.push({currRow+1,currCol});
                        grid[currRow+1][currCol] = '0';
                    }
                    //check left
                    if(currCol-1 >=0 and grid[currRow][currCol-1]=='1'){
                        qu.push({currRow,currCol-1});
                        grid[currRow][currCol-1] = '0';
                    }
                    //check down
                    if(currCol+1 < col and grid[currRow][currCol+1] == '1'){
                        qu.push({currRow,currCol+1});
                        grid[currRow][currCol+1] = '0';
                    }
                    
                }
            }
        }
        return cc;
        
    }
};