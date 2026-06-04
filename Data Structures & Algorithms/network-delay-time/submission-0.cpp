class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> edges;

        //building the adj list
        for(const auto& time: times) 
            edges[time[0]].emplace_back(time[2],time[1]);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0,k}); //weight and node

        set<int> visited;
        int t = 0; //track the time

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int w1 = curr.first, n1 = curr.second;

            if(visited.count(n1)) continue; //skip 

            visited.insert(n1);
            t = w1;


            if(edges.count(n1)) //if it has edges 
            for(const auto& next: edges[n1]) {
                int w2 = next.first, n2 = next.second;

                if(!visited.count(n2))
                    pq.push({w1+w2,n2});
            }
        }

        return visited.size() == n ? t : -1;
        
    }
};
