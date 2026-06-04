class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        vector<vector<int>> soln;
        for(auto i = points.begin(); i !=  points.end(); i++) {
            int x = (*i)[0],y = (*i)[1]; //remember to do (*i) otherwise operator precedence issue
            int dist  = x*x + y*y;  
            pq.push({dist, *i});
            if(pq.size() > k) pq.pop();
        } 

        while(!pq.empty()) {
            auto node = pq.top();
            soln.push_back(node.second);    //use second, node[1] wont work
            pq.pop();
        }

        return soln;
    }
};
