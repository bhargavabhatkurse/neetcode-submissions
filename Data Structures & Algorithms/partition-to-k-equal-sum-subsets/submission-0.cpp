class Solution {
public:
    bool backtracking(vector<int>& nums,vector<int>& subsets,int i, int size) {
    if(i == nums.size()) return true;
    
    for(int j = 0; j < subsets.size();j++) {//think of subsets like boxes
        if(subsets[j] + nums[i] <= size) {
            subsets[j] += nums[i];
            if(backtracking(nums,subsets,i+1,size)) return true;
            subsets[j] -= nums[i];
        }
        if(subsets[j] == 0) break; //optimisation
    }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum % k != 0) return false;
        
        int size = sum / k;
        vector<int> subsets(k,0); //k subsets, intially 0
        sort(nums.rbegin(),nums.rend());

        return backtracking(nums,subsets,0,size);
    }
};