
//check all submissions
class DSU {
    vector<int> Parent, Size;
public:
    DSU(int n) : Parent(n + 1), Size(n + 1, 1) {
        for (int i = 0; i <= n; i++) Parent[i] = i; //each node is a component
    }

    int find(int node) {
        if (Parent[node] != node)
            Parent[node] = find(Parent[node]);
        return Parent[node];
    }

    bool unionSets(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;

        if (Size[pu] < Size[pv]) swap(pu, pv);
        Size[pu] += Size[pv];
        Parent[pv] = pu;
        return true;
    }

    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        DSU dsu(N * N); //all nodes in the grid

        vector<tuple<int, int, int>> positions;
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++)
                positions.emplace_back(grid[r][c], r, c);

        sort(positions.begin(), positions.end()); //to demonstrate passage of time. each cell becomes avaialbe at grid[cell] time
        
        vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        for (auto& [t, r, c] : positions) { //when each position becomes available
            for (auto& [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < N && nc >= 0 &&
                    nc < N && grid[nr][nc] <= t) { //if its reachable within time t
                    dsu.unionSets(r * N + c, nr * N + nc); //make it a single component
                }
            }
            if (dsu.connected(0, N * N - 1)) return t; //check if source and dest are connected (return this min t)
        }
        return N * N;
    }
};
