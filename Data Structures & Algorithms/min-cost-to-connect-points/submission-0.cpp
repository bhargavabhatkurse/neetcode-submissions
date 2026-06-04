//kruskals MST
class DSU {
public: 
 vector<int> parent, size;

 DSU(int n): parent(n+1), size(n+1, 1) {
    for(int i = 0;i<n;i++) parent[i] = i; //every node is the parent
 }

int find(int node) {
 if(parent[node] != node) {
    parent[node] = find(parent[node]);
 }
  return parent[node];
}

bool unionset(int u, int v) {
    int pu = find(u), pv = find(v);
    if(pu == pv) return false;
    if(size[pu] < size[pv]) swap(pu,pv);
    size[pu] += size[pv]; //join the smaller component to the larger
    parent[pv] = pu;

    return true;
}

};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        vector<array<int,3>> edges;
        
        for(int i= 0; i<n;i++) {
            for(int j= i+1; j<n;j++) {//j = i+1 
             int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
             edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(),edges.end());

        int res = 0;
        for(auto& [dist,u,v]: edges) {
            if(dsu.unionset(u,v)) {
                res += dist;
            }
        }

        return res;

    
    }
};
