class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // //bruteforce  - nlogn
        // vector<vector<int>> soln;
        // vector<vector<int>> temp;
        // for(auto i = 0; i < points.size(); i++) {
        //     int x = points[i][0],y = points[i][1]; //remember: here, precedence is not required because we are not dealing with 
        //     int dist  = x*x + y*y;  
        //     temp.push_back({dist,i});
        // }

        // sort(temp.begin(), temp.end());
        // int i = 0;
        // while(k-- > 0) {
        //     soln.push_back(points[temp[i++][1]]); //push the point at that index
        // }

        // return soln;

        // //minheap soln: push all elements, pop the top k [nlogn(to build) + klogn(to pop)] or [n(heapify) + klogn(to pop)] space = n
        // auto cmp = [](const vector<int>& a, const vector<int>& b) {
        //     return a[0]*a[0] + a[1]*a[1] > b[0]*b[0] + b[1]*b[1]; //remember this
        // };

        // priority_queue<vector<int>,vector<vector<int>>, decltype(cmp)> pq(cmp); //min-heap
        // vector<vector<int>> soln;
        
        // for(auto i = points.begin(); i !=  points.end(); i++) {  
        //     pq.push(*i); //push the point (dist calc is in the cmp function)
        // } 

        // while(k-- > 0) {
        //     auto node = pq.top();
        //     soln.push_back(node);    //use second, node[1] wont work - we are pushing a vector
        //     pq.pop();
        // }

        // return soln;

        //maxheap soln: keeps the closest k points - o(nlogk) n insertions logk per operation

        priority_queue<pair<int,vector<int>>> pq; //maxheap
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
