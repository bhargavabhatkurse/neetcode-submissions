class Solution {
public:
    string topo_kahns(unordered_map<char, unordered_set<char>>& adj,unordered_map<char, int>& indegree) {
        queue<char> q;
        string res = "";
        for (auto &[c, deg] : indegree) {
            if (deg == 0) {
                q.push(c);
            }
        }

        while(!q.empty()) {
            char c = q.front();
            q.pop();
            res += c;

            for(auto nei: adj[c]) {
                    indegree[nei]--;
                    if(indegree[nei] == 0)
                        q.push(nei);
            }
        }  

        return res.size() == adj.size() ? res: "";

    }

    string res = ""; 
    unordered_map<char, int> state;
    bool dfs_topo(unordered_map<char, unordered_set<char>>& adj, char u) {
    //mixing topological order and cycle detection in 1

    if (state[u] == 1)
        return false;          // cycle found
    if (state[u] == 2)
        return true;           // already processed
    
    state[u] = 1;              // mark as visiting
    
    for (char v : adj[u]) {
        if (!dfs_topo(adj, v))
            return false;
    }

    state[u] = 2;              // finished
    res.push_back(u);          // postorder
    return true;
}

    string foreignDictionary(vector<string>& words) {
       unordered_map<char, unordered_set<char>> adj; //for Kahns, we a set to avoid duplicate 
        unordered_map<char, int> indegree;

        //create the nodes
        for(auto& w: words)
            for(char c: w) {
                adj[c];
                indegree[c] = 0;
            }

        for (size_t i = 0; i < words.size() - 1; ++i) { //size_t is used for array iterations (it is the return type of .size() function)
            string w1 = words[i], w2 = words[i+1];
            int minLen = min(w1.length(),w2.length());
            if(w1.length() > w2.length() && w1.substr(0, minLen) == w2.substr(0, minLen)) {
                    return ""; //claim in invalid, and topological order doesnt exist
            }

            //check char by char
            for (size_t j = 0; j < minLen; ++j) {
                    if (w1[j] != w2[j]) { //w1 preceeds
                        if (!adj[w1[j]].count(w2[j])) { //avoid duplicate insertions of edges (update indegree only if its new edge)
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                        break;
                    } //need to check only for one non-matching character
                }
        }

        //find topological order
        //return topo_kahns(adj,indegree);


        for(auto& [c,neigh]: adj) //we are doing this because the there can be many components
            if(!dfs_topo(adj,c)) return ""; //cycle -> so topo sort
        
        reverse(res.begin(),res.end()); //convert from postorder to correct
        return res;
        }


};
