class Solution {
public:
   unordered_map<int,bool> vis;
    bool dfs(vector<vector<int>> adj,int start, int end) {
            if(start == end) return true;
            vis[start] = true;
            for(auto i: adj[start]) {
                if(!vis[i]) {
                    vis[i] = true;
                    if(dfs(adj,i,end)) return true;
                }
            }
             return false;           
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<bool> ans;

        for(auto x: prerequisites) {
            adj[x.at(0)].push_back(x.at(1));
        }

        for(auto x: queries) {
            vis.clear(); //because we made it global
            if(dfs(adj,x.at(0),x.at(1)))
                ans.push_back(true);
            else 
                ans.push_back(false);
        }
        return ans;
    }
};