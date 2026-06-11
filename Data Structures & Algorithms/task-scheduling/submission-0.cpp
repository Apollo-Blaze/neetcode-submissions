class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> mh;
        deque<pair<int,int>> check;
        int t=0;
        unordered_map<char,int> m;
        for(auto x: tasks) m[x]+=1;
        for(auto x:m) mh.push(x.second);
        while(true){
            if(mh.empty() && check.empty()) break;
            t++;
            if(!check.empty() && check.front().second==t){
                mh.push(check.front().first);
                check.pop_front();
            }
            if(!mh.empty()){
                int a=mh.top();
                mh.pop();
                a--;
                if(a==0)continue;
                check.push_back({a,t+n+1});
            }
        }
        return t;
    }
};
