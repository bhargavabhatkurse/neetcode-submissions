class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //consecutive sequence != subsequence (the order doesnt matter)
        int len = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        
        //element i is the start of the sequence only if
        //the value i-1 doesnt exist in the hash set
        for(auto x: s) {
            if(!s.count(x-1)) { //valid candidate
            int curr_len = 1;
            int curr = x;
            while(s.count(curr+1)) {
                curr_len++;
                curr++;
            }
              len = max(curr_len, len);
            }
        }
        return len;

    }
};
