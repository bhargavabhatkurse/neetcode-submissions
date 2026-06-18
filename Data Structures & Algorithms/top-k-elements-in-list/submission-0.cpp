class Solution {
public:
vector<int> sorting_method(vector<int>& nums, int k) {
     //O(nlogn) 
    unordered_map<int,int> count;
    for(auto& x : nums) count[x]++;
    vector<vector<int>> temp;
    for(auto& p : count) {
        temp.push_back({p.second, p.first});
    }
    sort(temp.rbegin(), temp.rend()); //we can sort 2d vector like this: compares first values of both
    vector<int> result;
    for(int i = 0; i < k; i++) 
        result.push_back(temp[i][1]);
    return result;
}
    vector<int> topKFrequent_heap(vector<int>& nums, int k) {
    //O(nlogk) 
    unordered_map<int,int> count;
    for(auto& x : nums) count[x]++;
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(auto& x: count) {
        pq.push({x.second, x.first});
        if(pq.size() > k) pq.pop();
    }
    vector<int> result;
    for(int i = 0; i < k; i++) {
        auto c = pq.top();
        result.push_back(c.second);
        pq.pop();
    }
    return result;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
    //bucket sort
    unordered_map<int,int> count;
    vector<vector<int>> bucket(nums.size() + 1);  // bucket from 0 to n (0 frequency is never used)

    for(auto& x : nums) count[x]++; //count the frequency

    for(auto& x: count) {
        bucket[x.second].push_back(x.first);
    }

    vector<int> result;
    //now start from the highest frequency bucket
    for(int i = bucket.size()-1; i>0; i--) {
        for(int n: bucket[i]) result.push_back(n);
        if(result.size() == k) return result;
    }
    }


};
