class Solution {
public:
    struct Edge {
        int cost, u, v;
        bool operator<(const Edge& other) const {
            return cost < other.cost;
        }
    };
    
    class UnionFind {
    public:
        vector<int> parent;
        
        UnionFind(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
        }
        
        int find(int x) {
            if(parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        
        bool unite(int x, int y) {
            x = find(x);
            y = find(y);
            if(x == y) return false;
            parent[y] = x;
            return true;
        }
    };
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> edges;
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int dist = abs(points[i][0] - points[j][0]) + 
                           abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());

        UnionFind uf(n);
        int totalCost = 0;
        int edgesUsed = 0;
        
        for(auto& edge : edges){
            if(uf.unite(edge.u, edge.v)){
                totalCost += edge.cost;
                edgesUsed++;
                if(edgesUsed == n-1) break;
            }
        }
        
        return totalCost;
    }
};