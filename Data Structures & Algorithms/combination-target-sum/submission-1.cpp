class Solution {
public:
    vector<vector<int> > result;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        soln(nums,0,0,target);
        return result;
    }

    void soln(vector<int>& nums,int sum,int start,int target) {

        if(sum == target) {
            result.push_back(path);
            return;
        }

        for(int i=start;i<nums.size();i++) {
            if(sum + nums[i] <= target) {
                path.push_back(nums[i]);
                soln(nums,sum + nums[i],i,target);
                path.pop_back();
            }
        }




    }

};
