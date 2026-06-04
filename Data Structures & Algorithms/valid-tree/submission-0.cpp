class DSU {
    vector<int> Parent;
    int comps;
public:
    DSU(int n) {
        comps = n;
        Parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            Parent[i] = i;
        }
    }

    int find(int node) {
        if (Parent[node] != node) {
            Parent[node] = find(Parent[node]);
        }
        return Parent[node];
    }

    bool unionNodes(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;

        comps--;

        Parent[pv] = pu;
        
        return true;
    }

    int components() {
        return comps;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }

        DSU dsu(n);

        for (auto& edge : edges) {
            if (!dsu.unionNodes(edge[0], edge[1])) { //if I find a edge which connects in the same component
                return false;
            }
        }
        return dsu.components() == 1; //if connected components are 1, it is a tree
    }
};
