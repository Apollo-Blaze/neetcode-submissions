class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto asc = [](vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        };
        sort(intervals.begin(), intervals.end(), asc);
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=res[res.size()-1][1]){
                res[res.size()-1][1]=max(res[res.size()-1][1],intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
