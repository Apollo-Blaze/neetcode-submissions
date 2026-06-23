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
    bool canAttendMeetings(vector<Interval>& intervals) {
        auto asc=[](Interval a, Interval b){
            return a.start<b.start;
        };
        sort(intervals.begin(),intervals.end(),asc);
        int prev=intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            if(prev>intervals[i].start) return false;
            prev=intervals[i].end;
        }
        return true;
    }
};
