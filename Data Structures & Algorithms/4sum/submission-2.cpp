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

    vector<vector<int>> fourSum_tp(vector<int>& nums, int target) {
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
                    long long sum = (long long)(nums[i]) + nums[j] + nums[left] +
                                    nums[right];  // make sure to make it a long long sum
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

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int>
            count;  // number of occurrences of x available to be used as the third element.

        for (int n : nums) {
            count[n]++;
        }

        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]--;  // third element should not selected the same as i
            if (i >= 1 && nums[i] == nums[i - 1]) continue;  // skip duplicates
            for (int j = i + 1; j < nums.size(); j++) {
                count[nums[j]]--;
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;  // skip duplicates(important: j > i+1)
                // The duplicate check is done after decrementing the count because even when you
                // skip a duplicate j, that element is still no longer available to be used as the
                // third element (k) for later iterations.

                for (int k = j + 1; k < nums.size(); k++) {
                    count[nums[k]]--;
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;

                      long long fourth = target - (nums[i] + nums[j] + 0LL + nums[k]);
                    
                    if (fourth < INT_MIN || fourth > INT_MAX) //check if fourth fits the int or not
                        continue;
                    
                    if (count[(int)fourth] > 0) res.push_back({nums[i], nums[j], nums[k], (int)fourth});
                }
            
                for (int k = j + 1; k < nums.size(); k++) {
                    count[nums[k]]++;
                }
            }
                // restore the counts of j after finishing all the j's
                // don't restore j after each iteration because we want to find k such that it is on
                // the right side of j (to guarantee no duplicate triplets)
                for (int j = i + 1; j < nums.size(); j++) {
                    count[nums[j]]++;
                }
                // The restoration is needed because count is reused for the next value of i.
            }

            return res;
        }
    };