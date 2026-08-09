class Solution {
public:
    int majorityElement_(vector<int>& nums) {
        int n = nums.size();
        //takes o(n) space too
        unordered_map<int,int> m;

        for(int num: nums) {
            m[num]++;
        }

        for(auto i: m) {
            if(m[i.first] > n/2)
            return i.first;
        }
    }

    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        //boyer mooore voting algorithm - 0(1) space too
        int el;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(count ==0) {
                el = nums[i]; //consider this a majority element now
                count++;
            }
            else if(nums[i] == el) count++;
            else count--;
        }
        cout<<el<<endl;

        //again check if it is actually majority
        count =0;
        for(auto num : nums) {
            if(num == el) count++;
        }
       
        return count > (n/2) ? el: -1;
    }
};