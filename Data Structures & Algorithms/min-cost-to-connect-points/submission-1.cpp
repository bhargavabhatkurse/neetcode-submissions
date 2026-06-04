class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //building the graph
        int n = points.size();
        unordered_map<int,vector<pair<int,int>>> adj;

        for(int i=0;i<n;i++)
         for(int j=i+1;j<n;j++) {
            int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
        adj[i].push_back({dist,j});
        adj[j].push_back({dist,i});
        }

    int res = 0;
    unordered_set<int> visit;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap; 
    minheap.push({0,0});

    while(visit.size()< n) //only take n-1 elements
    {
        auto curr = minheap.top();
        minheap.pop();
        int cost = curr.first;
        int i = curr.second;

        if(visit.count(i)) continue; //this is like lazy dijstra

        res+= cost;
        visit.insert(i);

        for(const auto& nei: adj[i]) {
            if(!visit.count(nei.second)) //index not visited
            minheap.push({nei.first, nei.second});
        }
    }
    return res;
    }
};
