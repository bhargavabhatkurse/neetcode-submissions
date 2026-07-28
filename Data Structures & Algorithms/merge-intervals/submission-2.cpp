class Solution {
public:

    static bool compare(vector<int>& a, vector<int>& b) {
            return a[0] < b[0]; // sort by start
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //greedy - optimal
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end(),compare); //sort by start
    
    ans.push_back(intervals[0]);

    for(int i = 1; i< intervals.size();i++) {
        if(intervals[i][0] <= ans.back()[1])  { //start of this is conflicting with end of previously inserted (therefore need to merge)
           
           ans.back()[1] = max(intervals[i][1], ans.back()[1]); //update the end as max of current end and the previous inserted interval end
        }

        else {
             ans.push_back(intervals[i]);
        }
    }

        return ans;
    }
};
