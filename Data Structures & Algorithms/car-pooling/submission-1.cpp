class Solution {
public:
    bool carPooling_bruteforce(vector<vector<int>>& trips, int capacity) {
        //bruteforce - o(n^2)
        
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

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //using min-heap - I need to repeatedly remove the event with the earliest ending time → min-heap.
        
        //sort by start time
        sort(trips.begin(),trips.end(),[](const vector<int>& a, const vector<int> &b){
            return a[1] < b[1];
        });

        //keeping {end,passenger} 
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int cur_passenger = 0;

        for(auto trip: trips) { //for every trip
        int passenger = trip[0], start = trip[1],end = trip[2];
        
        while(!pq.empty() && pq.top().first <= start) {
            cur_passenger -= pq.top().second;
            pq.pop();
        }
        cur_passenger += passenger;
        if(cur_passenger > capacity) return false;
        
        pq.push({end,passenger});
        }

        return true;
    }
};
