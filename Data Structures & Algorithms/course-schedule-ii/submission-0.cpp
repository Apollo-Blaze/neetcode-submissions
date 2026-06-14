class Solution {
public:
    vector<vector<int>> grid;
    vector<int> state;
    vector<int> res;
    bool dfs(int i){
        if(state[i]==1) return true;
        if(state[i]==2) return false;
        state[i]=1;
        for(auto x:grid[i]){
            if(dfs(x)) return true;
        }
        state[i]=2;
        res.push_back(i);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        grid.assign(n,vector<int>());
        state.assign(n,0);
        //adj_list
        for(auto x:p){
            grid[x[0]].push_back(x[1]);
        }
        //check loop
        for(int i=0;i<n;i++){
            if (dfs(i)) return {};
        }
        //topological sort
        return res;
    }
};
