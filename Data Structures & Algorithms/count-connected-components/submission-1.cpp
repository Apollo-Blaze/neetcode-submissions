class Solution {
public:
    vector<int> state;
    vector<vector<int>> adj;
    
    void dfs(int node){
        state[node] = 1;  
        for(int neighbor : adj[node]){
            if(state[neighbor] == 0)
                dfs(neighbor);
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        state.assign(n, 0);
        adj.assign(n, vector<int>());

        for(auto& x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int components = 0;
        for(int i = 0; i < n; i++){
            if(state[i] == 0){
                dfs(i);
                components++;  
            }
        }
        return components;
    }
};