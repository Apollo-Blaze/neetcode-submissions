/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts;
        vector<int> ends;
        for(auto x:intervals){
            starts.push_back(x.start);
            ends.push_back(x.end);
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        int count=0;
        int maxCount=0;
        int i=0,j=0;
        while(i<starts.size()){
            if(starts[i]<ends[j]){
                count++;
                maxCount=max(maxCount,count);
                i++;
            }
            else if(starts[i]>=ends[j]){
                count--;
                j++;
            }
        }
        return maxCount;
    }
};
