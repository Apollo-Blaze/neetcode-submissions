class Solution {
public:
    vector<pair<int,int>> add={{0,1},{1,0},{-1,0},{0,-1}};

    void dfs(vector<vector<int>>& heights,int i,int j,vector<vector<bool>>& sea){
        if(sea[i][j]==false){
            sea[i][j]=true;
            for(auto x: add){
                int ni=i+x.first;
                int nj=j+x.second;
                if(ni>=heights.size()||ni<0||nj<0||nj>=heights[0].size()) continue;
                if(heights[ni][nj]>=heights[i][j])dfs(heights,ni,nj,sea);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) dfs(heights,i, 0, pacific);
        for(int j=0; j<n; j++) dfs(heights,0, j, pacific);
        for(int i=0; i<m; i++) dfs(heights,i, n-1, atlantic);
        for(int j=0; j<n; j++) dfs(heights,m-1, j, atlantic);
        vector<vector<int>> res;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
        return res;
    }
};
