class Solution {
    vector<vector<int> > results;
    vector<int> temp;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end()); //remember to sort first in questions having duplicates in the array
        soln(nums,0);
        return results;
    }

    void soln(vector<int>& nums,int index) {
        results.push_back(temp);

        for(int i = index;i<nums.size();i++) {
            if(i>index && nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);
            soln(nums,i+1);
            temp.pop_back();
        }

    }
};
