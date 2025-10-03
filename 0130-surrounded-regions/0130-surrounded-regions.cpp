class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};
        queue<pair<int,int>> qu;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if ((i == 0 || j == 0 || i == n-1 || j == m-1) && board[i][j] == 'O') {
                    qu.push({i, j});
                    board[i][j] = '#'; // mark as safe
                }
            }
        }

        while(!qu.empty()){
            auto cell = qu.front();
            qu.pop();
            int i = cell.first;
            int j = cell.second;
            for(int d =0;d<4;d++){
                int nr  = i+dir[d][0];
                int nc = j+dir[d][1];
                // this condition for the connected cell for boundary
               if(nr>=0 and nc>=0 and nr<n and nc<m and board[nr][nc] == 'O'){
                    board[nr][nc] = '#';
                    qu.push({nr,nc});
                }
            }
        }

        // 3. Flip the remaining 'O's to 'X', and '#' back to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }

        
    }
};