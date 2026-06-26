class Solution {
public:

//Check all Submissions: 

     bool dfs(const string& src, vector<string>& res, unordered_map<string, vector<string>>& adj, int targetLength) {
                //dfs backtracking - o(EV) - E recursive calls(tickets) × O(V) for erasing and inserting in adj[src] = O(EV)
                
                if(res.size() == targetLength) return true; //if all edges are covered (path = E+1)

                
                vector<string> neighbours= adj[src];

                for(int i = 0; i < neighbours.size(); i++) //for all neighbours
                {
                  string v = neighbours[i]; //conside this neighbour
                  res.push_back(v);
                  adj[src].erase(adj[src].begin()+i);//delete the neighbour (to not visit it again)
                  if(dfs(v,res,adj,targetLength)) return true;
                  res.pop_back();
                  adj[src].insert(adj[src].begin()+i,v);//delete the neighbour (to not visit it again
                }
                return false;
             }


    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //sorting helps to get the lexelogical order

        sort(tickets.begin(), tickets.end());
        unordered_map<string, vector<string> > adj; 
        //creating an adj list
    //before sorting
    //     {
    // {"JFK", "SFO"},
    // {"ATL", "JFK"},
    // {"JFK", "ATL"},
    // {"JFK", "LAX"}
    //  }
    

    //after sorting - now when we do jfk.push_back, it will be in lexicological order
    // {
    // {"ATL","JFK"},
    // {"JFK","ATL"},
    // {"JFK","LAX"},
    // {"JFK","SFO"}
    // }

        for(auto ticket : tickets) {
                adj[ticket[0]].push_back(ticket[1]);
        }

        vector<string> res = {"JFK"}; //always starting from jfk

        dfs("JFK", res, adj, tickets.size() + 1); //If a path uses every edge E exactly once, total vertices(itenary on the path is E+1
        return res;
    }
};
