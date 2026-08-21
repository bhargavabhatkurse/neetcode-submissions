class Solution {
public:
//same like matchstick problem
    bool backtracking(vector<int>& nums,vector<int>& subsets,int i, int size) {
        //i: which number I am placing
    if(i == nums.size()) return true;  //I could place all the numbers
    for(int j = 0; j < subsets.size();j++) {//think of subsets like  boxes (which box will the ith number go in)
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
        sort(nums.rbegin(),nums.rend()); //optimisation to catch unfeasible solutions early

        return backtracking(nums,subsets,0,size);
    }
};