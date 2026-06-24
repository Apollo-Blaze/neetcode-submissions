class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        auto asc=[](vector<int> a,vector<int> b){
            return a[0]<b[0];
        };
        sort(intervals.begin(),intervals.end(),asc);
        vector<int> res;
        for(auto x:queries){
            bool flag=false;
            int minSize=INT_MAX;
            for(auto y: intervals){
                if(y[0]<=x && y[1]>=x){
                    minSize=min(minSize,y[1]-y[0]+1);
                    flag=true;
                }
                if(y[0]>x) break;
            }
            if(flag) res.push_back(minSize);
            else res.push_back(-1);
        }
        return res;
    }
};
