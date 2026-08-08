class Solution {
public:
    int height_(int root, vector<vector<int>>& adj) {
        queue<pair<int,int>> q;
        unordered_set<int> visited;
        int height = 0;
        q.push({root,height});
        visited.insert(root);

        while(!q.empty()) {
            auto [node,hei] = q.front();q.pop();
            height = max(height,hei);

            for(auto nei: adj[node]) { //node is an int, therefore use adj[node]
                if(!visited.count(nei)) {
                    q.push({nei, hei+1});
                    visited.insert(nei);
                }
            }
        }
         return height;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int height = INT_MAX;

        vector<vector<int>> adj(n);
        for(auto edge: edges) {
            //undirected
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<pair<int,int>> temp;
        for(int i =0; i < n; i++) {
            int curr_height = height_(i,adj);
            temp.push_back({i,curr_height});
            height = min(height,curr_height);
        }

        vector<int> ans;
        for(auto [i,hei]: temp) {
            if(height == hei) ans.push_back(i);
        }

        return ans;
    }
};