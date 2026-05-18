class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> grid(9, vector<bool>(9, false));

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                
                int num = board[i][j] - '1';  // maps '1'-'9' to 0-8
                int gridIdx = (i/3)*3 + (j/3); // maps (i,j) to 0-8
                
                if(row[i][num] || col[j][num] || grid[gridIdx][num])
                    return false;
                
                row[i][num] = true;
                col[j][num] = true;
                grid[gridIdx][num] = true;
            }
        }
        return true;
    }
};