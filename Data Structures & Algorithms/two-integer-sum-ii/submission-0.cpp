class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;

        while(left<=right) {
            if(numbers[left] + numbers[right] == target) return {left+1, right+1}; //this is how you return an inline vector

            else if(numbers[left] + numbers[right] > target) {
                right--; //can't include the large right element
            }
            else left++; //because the sum is too small, we need to include a larger number
        }
    }
};
