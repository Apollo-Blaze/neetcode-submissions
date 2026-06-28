class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> edges;
        for(auto& time : times){
            int r = time[0];
            int a = time[1];
            int w = time[2];
            edges[r].push_back({a, w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mh;
        mh.push({0,k});
        unordered_set<int> visited;
        int tt=0;
        while(!mh.empty()){
            pair<int,int> t=mh.top();
            mh.pop();
            if(visited.find(t.second)!=visited.end()) continue;
            tt=max(tt,t.first);
            visited.insert(t.second);
            for(auto x:edges[t.second]){
                if(visited.find(x.first)==visited.end()){
                    mh.push({t.first+x.second,x.first});
                }
            }
        }
        
        return visited.size()==n?tt:-1;
    }
};
