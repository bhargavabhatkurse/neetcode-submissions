
class Solution {
public:
    int subarraySum_(vector<int>& nums, int k) {
        //bruteforce 
        int count = 0;
        for(int i = 0; i < nums.size();i++) {
            int sum = 0;
            for(int j = i; j < nums.size();j++) {
                sum += nums[j];
                if(sum == k) count++;
            }
        }
        return count;
    }
    int cumulativeSum(vector<int>& nums, int k) {
        //cumulative_sum (so that we don't have to calculate the sum everytime)
        //sum[i] is the sum from start to i-th element
        int count = 0;
        int n = nums.size();
        vector<int> sum(n+1);
        sum[0] = 0;
        for(int i = 1; i <= nums.size(); i++)    
        sum[i] = sum[i-1] + nums[i-1]; 

        for(int start = 0; start < nums.size(); start++)    
         for(int end = start + 1; end <= nums.size(); end++) { //remember where end ends
            int sum_total = sum[end] - sum[start];
         if(sum_total == k) count++;
         }
         return count;
    }
    
    int subarraySum_1(vector<int>& nums, int k) {
        //now we want to optimise space and not use extra sum array
        //o(1) space n^2 time complexity
        int count = 0;
        for(int start = 0; start < nums.size(); start++)   {  
            int sum_total = 0;
         for(int end = start; end < nums.size(); end++) { //remember where end ends
            sum_total += nums[end];
         if(sum_total == k) count++;
         }
        }

         return count;
    }

    int subarraySum(vector<int>& nums, int k) {
        int count  = 0; 
        unordered_map<int,int> m; //keeps track of prefixes and their counts
        m[0] = 1; //base case 
        int cur_sum = 0;
        for(int i =0; i < nums.size();i++) {
            cur_sum += nums[i];
            //prefix[i] - prefix[j-1] = k | subarray[j.....i]
            if(m.find(cur_sum-k) != m.end()) {
                count += m[cur_sum -k];
            }
        m[cur_sum]++; //I have seen this sum one more time
        }
        return count;
    }
};