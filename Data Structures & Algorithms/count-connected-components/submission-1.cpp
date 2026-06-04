class DSU {
public:
    vector<int> parent;

    DSU(int n) { //constructor
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        int cur = node;

        if(cur == parent[cur]) return cur;
        
        return find(parent[cur]);
    }

    bool unionSets(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        
        if (pu == pv) {
            return false;
        }
        
        parent[pv] = pu; //make one a parent of other
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int res = n; //initially everyone is a component

        for (auto& edge : edges) {
            if (dsu.unionSets(edge[0], edge[1])) {
                res--;
            }
        }
        return res;
    }
};