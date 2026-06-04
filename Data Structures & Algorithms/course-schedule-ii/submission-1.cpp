class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> soln;

        for(auto& pre: prerequisites) {
            indegree[pre.at(0)]++; //course
            adj[pre.at(1)].push_back(pre.at(0)); //preq -> course
        }

        queue<int> q;
        for(int i = 0; i< numCourses; i++) {
            if(indegree[i] == 0 ) q.push(i);
        }

        int finish = 0;
        while(!q.empty()) {
            int curr = q.front();
            soln.push_back(curr);
            finish++;
            q.pop();

            for(int neighbour: adj[curr]) {
                indegree[neighbour]--;

                if(indegree[neighbour] == 0) q.push(neighbour);
            }
        }


         vector<int> empty;
        return finish == numCourses ? soln :empty;


    }
};
