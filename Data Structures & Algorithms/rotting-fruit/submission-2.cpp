class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int lvl=0;
        int nlvl=0;
        int t=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    lvl++;
                    q.push({i, j});
                }
            }
        }
        int dirs[][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            lvl--;
            for(auto [di, dj] : dirs){
                int ni = i + di, nj = j + dj;
                if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1){
                    grid[ni][nj] = 2;
                    q.push({ni, nj});
                    nlvl++;
                }
            }
            if(lvl==0 && nlvl!=0){
                lvl=nlvl;
                nlvl=0;
                t++;
            }
        }
        for(auto x:grid){
            for(auto y:x){
                if(y==1) return -1;
            }
        }
        return t;
    }
};
