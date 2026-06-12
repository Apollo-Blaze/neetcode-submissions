class Solution {
public:
    int maxArea=0;
    int dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0)return 0;
        else{
            grid[i][j]=0;
            return dfs(i,j+1,grid)+dfs(i,j-1,grid)+dfs(i+1,j,grid)+dfs(i-1,j,grid)+1;
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    maxArea=max(dfs(i,j,grid),maxArea);
                }
            }            
        }
        return maxArea;
    }
};



