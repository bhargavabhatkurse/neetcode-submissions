class Solution {
    vector<vector<int> > results;
    vector<int> temp;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        soln(nums,0);
        return results;
    }

    void soln(vector<int>& nums,int index) {
        
        results.push_back(temp);

        for(int i=index;i<nums.size();i++) {
            temp.push_back(nums[i]);
            soln(nums, i + 1);
            temp.pop_back();
        }
    }
};
