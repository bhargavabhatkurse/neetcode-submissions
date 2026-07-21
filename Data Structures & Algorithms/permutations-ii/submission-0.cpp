class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> visited;

    void backtrack(vector<int>& nums) {

        //Permutations → No startIndex - remember 
        //[1,2] ≠ [2,1]

        // After choosing 1, you still need to be able to choose any remaining unused element, including elements that originally appeared before others.
        
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (visited[i]) continue;

            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) //important: skip if visited
                continue;

            visited[i] = true;
            path.push_back(nums[i]);

            backtrack(nums);

            path.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        visited.assign(nums.size(), false);
        backtrack(nums);

        return result;
    }
};