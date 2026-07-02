class Solution {
public:
//here, we go from impossible to possible. 
//The boundary where it changes -> we use binary search for these kind of problems
    long long helper(vector<int>& piles, int i) {
        long long total = 0;
        for(int n : piles) {
            total += ceil((double)n/i);
        }
        return total;
    }

    int minEatingSpeed_1(vector<int>& piles, int h) {
    //range [1,max(array)]
    int low = 1; //eating cant be from 0;
    int high = *max_element(piles.begin(),piles.end()); //remember
    int res = high; // the maximum eating capacity is the max element of the array
    
    while(low<= high) {
        int mid = low + (high - low)/2;
        long long time = helper(piles, mid);

        if(time <= h) {
                res = mid;
                high = mid -1; //less than mid is also possible
        }
        else low = mid + 1; //all less than mid is also not possible
    }
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int speed = 1;
        while (true) {
            long long totalTime = 0;
            for (int pile : piles) {
                totalTime += ceil(static_cast<double>(pile) / speed);
            }

            if (totalTime <= h) {
                return speed;
            }
            speed++;
        }
    }
};
