class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        //range = [1,nums.size() - 1];

        //bruteforce - sort and check (n + nlogn = nlogn)

        // //using hashset
        // unordered_set<int> st;
        // for(int i : nums) {
        //     if(st.count(i)) return i;
        //     st.insert(i);
        // }

        // return -1;

        // //using array - no difference in time complexity with hashset but generally considered better
        // vector<int> seen(nums.size(),0);
        // for(int num: nums) {
        //     if(seen[num - 1] == 1) return num; //already seen
        //     seen[num-1] = 1;
        // }

        // //negative marking to save space
        // //we need the abs as while traversing we are negating and we might get -4 instead of 4, but the actual index we need to calcute is abs(-4)-1 = 3
    
        // for(int num: nums) {
        //     if(nums[abs(num)-1] < 0) return num; //already seen
        //     nums[abs(num)-1] *= -1;
        // }

        // //using bitmap 
        // int x = 0;
        // for(int i : nums) {
        //     if(x & 1<<i) return i;
        //     int mask = 1<<i;
        //     x |= mask;
        // }
        // return -1;
        

        // //2 pointers
        // //treat the index as nodes and the value as the pointer
        // //(0 to n indices are nodes, and the values will be from 1 to n)
        // int slow = 0, fast = 0;
        // while(true) {
        //     slow = nums[slow];
        //     fast = nums[nums[fast]];

        //     if(slow == fast) break; //they can meet anywhere, not at the start of the cycle
        // }

        // int slow2 = 0; //from the start of the list
        // //floyds proof: both slow and slow2 will require x steps to reach the entrance of the cyle
        // //therefore, they will meet together

        // while(true) {
        //     //both move one step
        //     slow2 = nums[slow2];
        //     slow = nums[slow];

        //     if(slow == slow2) return slow;

        //     //Important: //duplicate here is the start of the cycle -> therefore this algo finds the start of the cycle in the linedlisk
        // }


        //binary search: 
        int n = nums.size();
        int l =1, r = n-1; //technically r = n+1 -1 = n
        int ans;
        while(l <= r) {
            int mid = l + (r-l)/2;
            int lessthanequal = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i]<= mid)
                    lessthanequal++;
            }
            if(lessthanequal <= mid) {
                l = mid + 1; //duplicate in right half (we are sure)
            }
            else {
                r = mid - 1; //we are sure duplicate is on left side
                ans = mid; //upper bound on the duplicate is mid. mid itself can be the duplicate here
            }
        }

        return ans;
    }
};
 