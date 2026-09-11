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
        auto compare = [](Interval &i1,Interval &i2){
            return i1.end<i2.end;
        };
        sort(intervals.begin(),intervals.end(),compare);
        int s = intervals[0].start,e = intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            int s2 = intervals[i].start,e2 = intervals[i].end;
            
            if(s2<e){
                return false;
            }
            s = max(s,s2);
            e = max(e,e2);
        }
        return true;
    }
};
