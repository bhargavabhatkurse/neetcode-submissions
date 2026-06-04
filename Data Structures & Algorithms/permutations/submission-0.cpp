class Solution {
public:
    vector<vector<int> > result;
    vector<int> path;
    vector<bool> used;

    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false);
        soln(nums);
        return result;
    }
    void soln(vector<int>& nums) {
        if(path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for(int i=0;i<used.size();i++)
            if(used[i] == false) {
                path.push_back(nums[i]);
                used[i] = true;
                soln(nums);
                used[i] = false;
                path.pop_back();
            }

    }
    
};
