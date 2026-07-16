class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //shortest path faster algorithm
        vector<int> prices(n, INT_MAX); //tracks the least price to reach that city
        prices[src] = 0;
        
        //create adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for(const auto& flight: flights) {
            adj[flight[0]].emplace_back(flight[1],flight[2]); 
        }

        // (currentCost, city, stopsUsed)
        queue<tuple<int,int,int>> q;
        q.push({0,src,0});

        while(!q.empty()) {
            auto [cost,node,stops] = q.front();
            q.pop();
            if(stops > k) continue;

            for (const auto& neighbor : adj[node]) {
                int nei = neighbor.first, w = neighbor.second;
                int nextCost = cost + w; //cost of this node + weight
                
                if (nextCost < prices[nei]) { //update
                    prices[nei] = nextCost;
                    q.push({nextCost, nei, stops + 1});
                }
            }
        }
        return prices[dst] == INT_MAX? -1: prices[dst];
    }
};
