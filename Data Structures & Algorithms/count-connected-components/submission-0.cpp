class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int> > adj(n);
            vector<bool> visit(n,false);

            //creating adjacency matrix
            for(auto &edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }

            int res = 0;
            for(int i=0;i<n;i++) {
                if(!visit[i]) {
                   res++;
                    dfs(adj,visit,i);

                }
            }
        return res;
    }


    void dfs(const vector<vector<int>> &adj, vector<bool> &visit, int node) {
        visit[node] = true; //mark as visited
        //visit its neighbours
        for(auto nei: adj[node]) {
            if(!visit[nei])
            dfs(adj,visit, nei);
        }
    }
  };
