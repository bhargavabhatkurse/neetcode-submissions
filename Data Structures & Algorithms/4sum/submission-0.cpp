class Solution {
   public:
    vector<vector<int>> fourSum_brute(vector<int>& nums, int target) {
        // bruteforce - n^4
        set<vector<int>> s;
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                for (int k = j + 1; k < nums.size(); k++)
                    for (int l = k + 1; l < nums.size(); l++)
                        if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                            vector<int> quadruplet = {nums[i], nums[j], nums[k], nums[l]};
                            sort(quadruplet.begin(),
                                 quadruplet.end());  // o(1) as only 3 elements are sorted
                            s.insert(quadruplet);
                        }
        for (auto x : s) result.push_back(x);
        return result;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 2 pointer approach
        sort(nums.begin(), nums.end());  // helps to skip the duplicates easily
        vector<vector<int>> result = {};

        for (int i = 0; i < nums.size();
             i++) {  // we will fix nums[i] and nums[j] and then find other two using two pointers
            if (i >= 1 && nums[i] == nums[i - 1]) continue;  // skip duplicates
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // skip duplicates

                // find the rest using 2 pointers
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    long long sum = (long long)(nums[i]) + nums[j] + nums[left] + nums[right]; //make sure to make it a long long sum
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        // skip the duplicates
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    } else if (sum < target) {
                        // too small
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};