class Solution {
public:
    void backtrack_(vector<int>& nums,int index,int& ans,vector<int>& path) {
        // n*2^n
        if(index == nums.size()) {
            int curr = 0; //identity for xor
            for(auto p: path) { //o(n)
               curr = curr^p;
            }
            ans += curr;
            return;
        }

        path.push_back(nums[index]);    //include
        backtrack_(nums,index+1,ans,path); 
        path.pop_back();
        backtrack_(nums,index+1,ans,path); //exclude it
    }

    void backtrack(vector<int>& nums,int index,int& ans,int curr) {
        // 2^n - no path vector here.
        if(index == nums.size()) {
            ans += curr;
            return;
        }

        backtrack(nums,index+1,ans,curr^nums[index]); //include it
    
        backtrack(nums,index+1,ans,curr); //exclude it
    }

    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        vector<int> path;
        //backtrack_(nums,0,ans,path);
        backtrack(nums,0,ans,0);
        return ans;
    }
};