class Solution {
public:
    vector<int> state;
    vector<vector<int>> adj;
    bool dfs(int n,int p){
        state[n] = 1; 
        for(auto x:adj[n]){
            if(x==p) continue;
            if(state[x] == 1) return true;
            if(state[x] == 0 && dfs(x, n)) return true;
        }
        state[n]=2;
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        state.assign(n,0);
        adj.assign(n,vector<int>());
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]); 
        }
        if(dfs(0, -1)) return false;
        for(int i=0;i<n;i++){
            if(state[i]==0) return false;
        }
        return true;
    }
};
