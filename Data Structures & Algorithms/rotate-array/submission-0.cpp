class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        while(k>0) {
            int temp = nums.back();
            for(int i = n-1; i >0; i--) {
                nums[i] = nums[i-1];
            }
            nums[0] = temp;
            k--;
        }
    }
};