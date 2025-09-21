class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string &word, int i, int j, int idx){
        if(idx == word.size()) return true; // word found
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] != word[idx]) 
            return false;
        
        char temp = board[i][j];
        board[i][j] = '#'; // mark visited
        
        bool found = dfs(board, word, i+1, j, idx+1) ||
                     dfs(board, word, i-1, j, idx+1) ||
                     dfs(board, word, i, j+1, idx+1) ||
                     dfs(board, word, i, j-1, idx+1);
        
        board[i][j] = temp; // backtrack
        return found;
    }
};
