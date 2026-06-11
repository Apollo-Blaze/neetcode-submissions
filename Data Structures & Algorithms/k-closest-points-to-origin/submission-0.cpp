class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<float,vector<float>,greater<float>> mh;
        unordered_map<float,vector<int>> check;
        for(int i=0;i<points.size();i++){
            float d=float(sqrt(pow(points[i][0],2)+pow(points[i][1],2)));
            check[d].push_back(i);
            mh.push(d);
        }
        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            res.push_back(points[check[mh.top()].back()]);
            check[mh.top()].pop_back();
            mh.pop();
        }
        return res;
    }
};
