class Solution {
public:
unordered_set<int> col;
unordered_set<int> nd; //r-c
unordered_set<int> pd; //r+c
vector<vector<string>> res;
    void dfs(int r,vector<string>& board, int n){
        if(r==n){
            res.push_back(board);
            return;
        }
        for(int c=0;c<n;c++){
            if(col.find(c)!=col.end()||nd.find(r-c)!=nd.end()||pd.find(r+c)!=pd.end()) continue;
            col.insert(c);
            nd.insert(r-c);
            pd.insert(r+c);
            board[r][c]='Q';
            dfs(r+1,board,n);
            col.erase(c);
            nd.erase(r-c);
            pd.erase(r+c);
            board[r][c]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n, '.'));
        dfs(0,board,n);
        return res;
    }
};
