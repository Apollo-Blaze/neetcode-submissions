class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0)
                    q.push({i, j});
            }
        }
        int dirs[][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            
            for(auto [di, dj] : dirs){
                int ni = i + di, nj = j + dj;
                if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj] > grid[i][j] + 1){
                    grid[ni][nj] = grid[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
    }
};
