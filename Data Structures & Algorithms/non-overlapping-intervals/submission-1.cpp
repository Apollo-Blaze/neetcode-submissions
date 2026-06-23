class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int prev;
        int count=0;
        auto asc=[](vector<int> a,vector<int> b){
            return a[0]<b[0];
        };
        sort(intervals.begin(),intervals.end(),asc);
        prev=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<prev){
                prev=min(prev,intervals[i][1]);
                count++;
            }
            else{
                prev=intervals[i][1];
            }
        }
        return count;
    }
};
