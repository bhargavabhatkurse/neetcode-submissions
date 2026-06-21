class Solution {
public: 
    int count(int num) {
        int iter = 0;

        //brian kernighan's trick
        while(num) {
            num &= num-1;
            iter++;
        }
        return iter;
    }

    vector<int> countBits(int n) {
        vector<int> res;
        for(int i= 0; i<=n; i++) {
            res.push_back(count(i));
        }
        return res;
    }
};
