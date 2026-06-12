class Solution {
public:
    int island=0;
    void dfs(int i,int j,vector<vector<char>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0')return;
        else{
            grid[i][j]='0';
            dfs(i,j+1,grid);
            dfs(i,j-1,grid);
            dfs(i+1,j,grid);
            dfs(i-1,j,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    island++;
                    dfs(i,j,grid);
                }
            }            
        }
        return island;
    }
};
