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

        //bruteforce if we count length for each element, instead of finding the candidate first

        //  sort(nums.begin(), nums.end());
        // if(nums.empty()) return 0;
        // int maximum = 1;
        // int counter = 1;

        // //same as finding longest subarray
        // for(int i = 1; i < nums.size();i++) {
        //     if(nums[i] == nums[i-1]) continue; //duplicate
        //     else if(nums[i] == nums[i-1] +1) counter++;
        //     else counter = 1;

        //     maximum = max(maximum, counter);
        // }

        // return maximum;


    }
};
