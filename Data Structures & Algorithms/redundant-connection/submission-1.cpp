class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n+1); //because nodes are from 1 to n

        for (int i = 0; i <= n; ++i)
        par[i] = i;

        for (const auto& edge : edges) {
            if (!Union(par, edge[0], edge[1]))
                return vector<int>{ edge[0], edge[1] }; //redundant edge
        }
        return {}; //no redundant edges


    }

    int Find(vector<int> &par, int n) {
        if(par[n] == n) return n;

        return Find(par,par[n]);
    }

    bool Union(vector<int>& par, int n1, int n2) {
        int p1 = Find(par, n1);
        int p2 = Find(par, n2);

        if (p1 == p2)
            return false;
       
        par[p2] = p1;
    
        return true;
    }
};
