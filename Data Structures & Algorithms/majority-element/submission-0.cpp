class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> m;

        for(int num: nums) {
            m[num]++;
        }

        for(auto i: m) {
            if(m[i.first] > n/2)
            return i.first;
        }
    }
};