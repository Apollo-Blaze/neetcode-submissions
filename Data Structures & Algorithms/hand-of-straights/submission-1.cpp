class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize) return false;
        sort(hand.begin(),hand.end());
        unordered_map<int,int> hm;
        for (auto x: hand){
            hm[x]+=1;
        }
        priority_queue<int,vector<int>,greater<int>> mh;
        for(auto x: hm){
            mh.push(x.first);
        }
        while(!mh.empty()){
            int k=groupSize;
            int m=mh.top();
            while(k){
                if(hm[m]){
                    hm[m]-=1;
                    if(hm[m]==0){
                        if(m!=mh.top()) return false;
                        mh.pop();
                    }
                    m+=1;
                    k--;
                }
                else return false;
            }
        }
        return true;
    }
};
