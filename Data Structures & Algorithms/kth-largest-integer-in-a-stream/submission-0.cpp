class KthLargest {
    priority_queue<int,vector<int>,greater<int>> q; 
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
      this->k = k;
      for(int i: nums) {
        q.push(i);
        if(q.size() > k) q.pop();
      }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > k)
              q.pop();
        return q.top();
    }
};
