class KthLargest {
    priority_queue<int,vector<int>,greater<int>> q; 
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
      this->k = k;
      for(int i: nums) {
        q.push(i);
        if(q.size() > k) q.pop(); //min heap will keep the kth largest seen so far
      }
    }
    
    int add(int val) {
      //bruteforce is sort the list each time and find the kth largest as n - k
        q.push(val);
        if(q.size() > k)
              q.pop();
        return q.top();
    }
};
