class Solution {
public:
    int shipWithinDays_linear(vector<int>& weights, int days) {
        //remember the question says within days, not exactly days
        int curr_cap = *max_element(weights.begin(),weights.end()); //capacity should be atleast te largest weight
        while(true) {
        int shipment_days = 1, capacity = curr_cap; 
        for(int w: weights) {
            if(capacity - w < 0) {
                //cant fit
                //need to increase to another extra day
                shipment_days++;
                capacity = curr_cap;
            }
        
            capacity -= w;
        }
            if(shipment_days <= days) return curr_cap;//minimum capacity required

            curr_cap++; //try by increasing the curr_capacity;
        }
    }

    bool possible(vector<int>& weights, int days, int cap) {
       
        int shipment_days = 1, capacity = cap; 
        for(int w: weights) {
            if(capacity - w < 0) {
                //cant fit
                //need to increase to another extra day
                shipment_days++;
                capacity = cap;
                if(shipment_days > days) return false;
            }
        
            capacity -= w;
        }
        
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        //binary search
        int l = *max_element(weights.begin(), weights.end()); //minimum capacity equired
        int r = accumulate(weights.begin(), weights.end(), 0); //maximum is shipping everything in 1 day
        int res = r; //max
        while (l <= r) {
            int cap = (l + r) / 2;
            if (possible(weights, days, cap)) {
                res = cap; 
                r = cap - 1;
            } else {
                l = cap + 1;
            }
        }
        return res;
    }
};