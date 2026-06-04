class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m = {}; 
        int difference;
        vector<int> soln;

        for(int i=0;i<nums.size();i++){
            difference = target - nums[i];
            if (m.find(difference) != m.end()) {
                soln.push_back(m[difference]);
                soln.push_back(i);
                break;
               }
            else m[nums[i]] = i;
    }

    return soln;
    }
};
