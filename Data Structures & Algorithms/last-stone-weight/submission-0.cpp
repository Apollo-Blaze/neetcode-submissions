class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>  mh;
        for(auto x: stones) mh.push(x);
        while(mh.size()>1){
            int x=mh.top();
            mh.pop();
            int y=mh.top();
            mh.pop();
            if(x==y)continue;
            mh.push(x-y);
        }
        if(mh.size()==0) return 0;
        return mh.top();
    }
};
