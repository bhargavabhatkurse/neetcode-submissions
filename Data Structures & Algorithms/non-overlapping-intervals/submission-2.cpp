class Solution {
public: static bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int count = 0;
    sort(intervals.begin(),intervals.end(),compare);

    int end = intervals[0][1]; //end of first interval
    for(int i = 1; i< intervals.size();i++) {
        if(intervals[i][0] < end)  {
            count++;
        }

        else {
            end = intervals[i][1];
        }
    }

        return count;
    }
};