class Solution {
public:
    vector<vector<int> > result;
    vector<int> subset;
    void soln(vector<int>& nums,int start,int k) {
        
        if(subset.size() == k) {
            result.push_back(subset);
            return;
        }

        for(int i=start;i<nums.size();i++) {
                subset.push_back(nums[i]);
                soln(nums,i+1,k);
                subset.pop_back();
        }
 }

    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n);
        iota(nums.begin(),nums.end(),1);
        soln(nums,0,k);
        return result;
    }

};