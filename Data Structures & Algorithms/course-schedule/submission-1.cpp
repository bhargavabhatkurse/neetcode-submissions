class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Kahn's algorithm - Topological sort

        vector<int> indegree(numCourses,0);
        vector<vector<int>> prereq(numCourses);

        for(const auto& pre: prerequisites) {
            indegree[pre[1]]++;
            prereq[pre.at(0)].push_back(pre.at(1)); //building adjacency list
        }

        queue<int> q;

        for(int i  = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
            q.push(i);
        }

        int finish = 0;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            finish++;

            for(int neighbour: prereq[curr]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) //add this to queue because this will be the next node in our topological sort
                    q.push(neighbour);
            }
        }


        return finish == numCourses;
    }
};
