class Solution {
public:
    bool dfs(vector<vector<char>>& board, int r, int c, int i, string word,int ROW, int COL,vector<vector<bool>>& path){
        if(i==word.size())return true;
        if(r<0||c<0||r>=ROW||c>=COL||word[i]!=board[r][c]||path[r][c]) return false;
        path[r][c]=true;
        bool res=(dfs(board,r+1,c,i+1,word,ROW,COL,path)||dfs(board,r-1,c,i+1,word,ROW,COL,path)||dfs(board,r,c+1,i+1,word,ROW,COL,path)||dfs(board,r,c-1,i+1,word,ROW,COL,path));
        path[r][c]=false;
        return res;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int ROW=board.size();
        int COL=board[0].size();
        vector<vector<bool>> path(ROW, vector<bool>(COL, false));;
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(dfs(board,i,j,0,word,ROW,COL,path)) return true;
            }
        }
        return false;
    }
};
