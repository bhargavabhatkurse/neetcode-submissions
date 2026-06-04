class Solution {
public:
 vector<vector<int> > result;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        soln(candidates,0,0,target);
        return result;
    }
   
    void soln(vector<int>& nums,int sum,int start,int target) {

        //if(nums[start-1] == nums[start]) return;

        if(sum == target) {
            result.push_back(path);
            return;
        }

        for(int i=start;i<nums.size();i++) {

            if (i > start && nums[i] == nums[i - 1]) 
                continue;

            if(sum + nums[i] <= target) {
                path.push_back(nums[i]);
                soln(nums,sum + nums[i],i+1,target);
                path.pop_back();
            }
        }


}

};
