class TimeMap {
public:unordered_map<string, unordered_map<int, vector<string>>> m;
    TimeMap() {
        //check all submissions
    }
    
    void set(string key, string value, int timestamp) {
        //o(1) opearation
        //space -> o(m*n) no of timestamps * no of keys
        m[key][timestamp].push_back(value); //there will be 1 value per timestamp (strictly increasing timestamp)
    }
    
    string get(string key, int timestamp) {
        //linear search - (n) no of timestamps
        int max_seen = INT_MIN;
        for(auto& [time,val]: m[key]) {
                if(time <= timestamp)
                max_seen = max(time,max_seen);
        }
        return max_seen == INT_MIN ? "" : m[key][max_seen][0];
    }

    
};
 