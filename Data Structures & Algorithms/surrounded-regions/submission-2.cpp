class Solution {
public:
    vector<pair<int,int>> next={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<char>>& board,int i,int j){      
        board[i][j]='Y';  
        for(auto x:next){
            int ni=i+x.first;
            int nj=j+x.second;
            if(ni>=0 && nj>=0 && ni<board.size() && nj<board[0].size() && board[ni][nj]=='O')dfs(board,ni,nj);
        }

    }
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O')
            dfs(board,i,0);
            if(board[i][board[0].size()-1]=='O')
            dfs(board,i,board[0].size()-1);
        }
        for(int j=0;j<board[0].size();j++){
            if(board[0][j]=='O')
            dfs(board,0,j);
            if(board[board.size()-1][j]=='O')
            dfs(board,board.size()-1,j);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='Y') board[i][j]='O';
                else board[i][j]='X';
            }
        }
    }
};
