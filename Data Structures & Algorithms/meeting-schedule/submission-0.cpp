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
        // //bruteforce - check all pairs (n^2)
        // for(int i = 0; i < intervals.size();i++) {
        //     Interval &x = intervals[i];
        // for(int j = i+1; j < intervals.size();j++) {
        //       Interval &y = intervals[j];
        //       if(min(x.end, y.end) > max(x.start, y.start)) //anyone starts before other ends
        //         return false;
        // }
        // }

        //sorting - nlogn
        sort(intervals.begin(),intervals.end(),[](Interval x, Interval y) {return x.start < y.start;});

        for(int i = 1; i < intervals.size();i++) {
            if(intervals[i-1].end > intervals[i].start) return false; //if the previous ends after start of next
        }

        return true;
    }
};
