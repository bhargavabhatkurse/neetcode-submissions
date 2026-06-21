class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    //     //bruteforce - n^3
    //     set<vector<int>> s;
    //     vector<vector<int>> result;
    //     for(int i=0; i < nums.size(); i++)
    //     for(int j=i+1; j < nums.size(); j++)
    //     for(int k=j+1; k < nums.size(); k++)
    //     if(nums[i] + nums[j] + nums[k] == 0) {
    //         vector<int> triplet = {nums[i],nums[j],nums[k]};
    //         sort(triplet.begin(),triplet.end()); // o(1) as only 3 elements are sorted
    //         s.insert(triplet);
    //     }
    // for(auto x: s) result.push_back(x);
    // return result;

    // //2 pointer approach
    // sort(nums.begin(),nums.end());//helps to skip the duplicates easily
    // vector<vector<int> > result = {};

    // for(int i=0; i < nums.size(); i++) {// we will fix nums[i] and then find other two using two pointers
    //     if(i >= 1 && nums[i] == nums[i-1]) continue; //skip duplicates
    //     int a = nums[i]; 
    //     if(a > 0) break; //no negative numbers to make sum = 0; (a is the smallest one)
    //     int left = i+1, right = nums.size()-1;
    //     while(left < right) {
    //     if(a + nums[left] + nums[right] == 0) {
    //         result.push_back({nums[i],nums[left],nums[right]}); 
    //             left++;
    //             right--; 
    //             //after finding one soln, modify left and right to find other solutions
    //         }
    //     else if(a + nums[left] + nums[right] < 0) left++; //sum too small
    //     else right--;
    //     }
    // }
    //     return result;


    //Hash Map
    sort(nums.begin(),nums.end());
    unordered_map<int,int> count; //number of occurrences of x available to be used as the third element.
    
    for(int n: nums) {
        count[n]++;  
    }

    vector<vector<int>> res;

    for(int i = 0 ; i < nums.size(); i++) {
        count[nums[i]]--; //third element should not selected the same as i 
    if(i>= 1 && nums[i] == nums[i-1]) continue; //skip duplicates
    for(int j = i+1 ; j < nums.size(); j++) {
         count[nums[j]]--;
        if(j> i+1 && nums[j] == nums[j-1]) continue; //skip duplicates(important: j > i+1)

        int target = -(nums[i] + nums[j]);

        if(count[target] > 0) res.push_back({nums[i],nums[j],target});
    }

    //restore the counts of j after finishing all the j's 
    //don't restore j after each iteration because we want to find k such that it is on
    //the right side of j (to guarantee no duplicate triplets)
    for(int j = i+1 ; j < nums.size(); j++) {
        count[nums[j]]++;
    }
    }

    return res;
    }
    
};
