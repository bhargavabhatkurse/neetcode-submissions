class Solution {
public:
    vector<int> productExceptSelf_(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n,-1);
        vector<int> next(n,-1);
        
        prev[0] = 1;
        for(int i = 1; i < n; i++)
        prev[i] = prev[i-1] * nums[i-1];

        next[n-1] = 1;
        for(int i = n-2; i >= 0; i--)
        next[i] = next[i+1] * nums[i+1];
        
        vector<int> result(n,-1);
        for(int i = 0; i < n; i++) {
            result[i] = prev[i] * next[i];
        }
        return result;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= postfix; //right array
            postfix *= nums[i];
        }
        return res;
    }

};
