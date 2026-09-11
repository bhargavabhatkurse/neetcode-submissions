class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //bruteforce
        
        //sort by start time
        sort(trips.begin(),trips.end(),[](const vector<int>& a, const vector<int> &b){
            return a[1] < b[1];
        });

         //"When trip i starts, how many passengers are currently in the car?"
        for(int i = 0; i < trips.size();i++) {
            int cur_passenger = trips[i][0];
            for(int j = 0; j < i;j++) {//look at previous
            if(trips[j][2] > trips[i][1]) //if ending later than start of this trip
            cur_passenger += trips[j][0];
            }
            if(cur_passenger > capacity) return false;
        }

        return true;
    }
};
