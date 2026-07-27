class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //fixed sliding window
        unordered_set<int> m;
        for(int i = 0; i < nums.size();i++) { 
          if(m.count(nums[i])) return true; //already in the window
          m.insert(nums[i]);
          if(m.size() > k) m.erase(nums[i-k]); //shrink the window
        }
        return false;
    }
};