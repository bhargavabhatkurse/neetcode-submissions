class Solution {
public:
    int atmost(vector<int>& A, int K) {
        int res = 0;
        unordered_map<int,int> count; //count of unique chracters
        int left = 0;
        
        for(int right = 0; right < A.size();right++) {
            if(count[A[right]] == 0) K--; //one unique found for the first time
            count[A[right]]++;

            //shrink if more than k uniques
            while(K < 0) {
                 count[A[left]]--;
                 if(count[A[left]] == 0) K++; //one unique is dropped
                 left++;
            }

            res += right - left + 1; //these many subarrays will be valid ending at 'right' (atmost k distinct)

        //     [left ... right]

        //     has at most K distinct elements.

        //     Therefore:

        //     [left ... right]
        //     [left+1 ... right]
        //     [left+2 ... right]
        //     ...
        //     [right ... right]

        //     also have at most K distinct elements.

        //     Removing elements from the left cannot introduce a new distinct element.

        //     So every one of these is valid.
        } 
        return res;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};