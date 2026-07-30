class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = 0, n2 = 0;
        vector<int> ans;

        while(n1 < m && n2 < n) {
            if(nums1[n1] < nums2[n2]) {
                ans.push_back(nums1[n1++]);
            }
            else {
                  ans.push_back(nums2[n2++]);
            }
        }

        while(n1 < m) {
            ans.push_back(nums1[n1++]);
        }
        
        while(n2 < n) {
           ans.push_back(nums2[n2++]);
        }

        for(int i = 0; i < n+m; i++) {
            nums1[i] = ans[i];
        }

    }
};