class TimeMap {
public:unordered_map<string, map<int,string>> m; //we need ordered map for binary search
    
       unordered_map<string, vector<pair<int,string>>> m_arr; //for upperbound from stract
    TimeMap() {
        //check all submissions
    }
    
    void set_1(string key, string value, int timestamp) {
        //o(1) opearation
        //space -> o(m*n) no of timestamps * no of keys
        m[key].insert({timestamp,value});//there will be 1 value per timestamp (strictly increasing timestamp)
        //we used insert as m[key] returns a map
    }
    
    string get_1(string key, int timestamp) {
        //Binary search - (logn) no of timestamps
        
        auto it = m[key].upper_bound(timestamp); //upperbound: gives first element greater than timestamp
        
        return it == m[key].begin() ? "" : prev(it)->second; //need to go one element back of the upperbound
    }

    void set(string key, string value, int timestamp) {
        //o(1) opearation
        //space -> o(m*n) no of timestamps * no of keys
        m_arr[key].push_back({timestamp,value});
    }

    
    string get(string key, int timestamp) {
        //Binary search - (logn) no of timestamps
        
        //auto it = m[key].upper_bound(timestamp); //upperbound: gives first element greater than timestamp
        //this doesnt work because upper_bound is not a member function of vector
        auto x = m_arr[key];
        int l = 0, h = x.size()-1;
        string ans ="";

        while(l<=h) {
            int m = l + (h-l)/2;
            if(x[m].first <= timestamp) { //remember <= for upperbound
            ans = x[m].second; //value can be a possible answer
                l = m+1; //check right subhalf for a more latest answer
            }
            else {
                h = m-1;
            }
        }
        return ans;
    }
};
 