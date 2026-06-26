class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //Hierholzer's Algorithm - takes o(E) time to build the eulerian circuit
        //https://www.youtube.com/watch?v=8MpoO2zA2l4
        
        unordered_map<string, deque<string>> adj;
        sort(tickets.begin(), tickets.end()); //lexicological smaller
        for (auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        //remember this syntax: for sorting the deque 
        // for (auto& [src, dests] : adj) {
        //     sort(dests.rbegin(), dests.rend());
        // }

        vector<string> res;
        //dfs("JFK", adj, res);
        dfs_iter("JFK", adj, res);
        reverse(res.begin(), res.end()); //it is because we were using push_back, there is no vector_push_front
        return res;
    }

    void dfs(const string& src, unordered_map<string, deque<string>>& adj, vector<string>& res) {
        //in Heirholzer algorithm, we go as deep as possible and add the node to the solution if it has no more 
        
        //(recursion)

        //outgoing edges, then we backtrack.
        // If you have outgoing edges, explore them and add only when no more outgoing edges.
        while(!adj[src].empty()) {
            string neigh = adj[src].front(); //smallest first (it is will like that because we sorted)
            adj[src].pop_front();
            dfs(neigh, adj, res);
        }

        //when there are no outgoing edges/neighbours, add it to res
        res.push_back(src);
        //remember to pass by reference in these kind of questions
    }


    void dfs_iter(const string& src, unordered_map<string, deque<string>>& adj, vector<string>& res) {
        //in Heirholzer algorithm, we go as deep as possible and add the node to the solution if it has no more 
        
        //(iteration)
        stack<string> st;
        st.push(src);

        //outgoing edges, then we backtrack.
        // If you have outgoing edges, explore them and add only when no more outgoing edges.
        while(!st.empty()) {
            string src = st.top();
            //why no pop here? answer below
           
        if(adj[src].empty()) {
              res.push_back(src);  //when there are no outgoing edges/neighbours, add it to res
                 st.pop(); //because since we ar eonly pushing one neighbour here(there is no while loop), the current src can hav more neighbours
        }
        else {string neigh = adj[src].front();
            adj[src].pop_front();
            st.push(neigh);
        }
        }


        //remember to pass by reference in these kind of questions
    }
};
