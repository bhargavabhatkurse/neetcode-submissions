class Solution {
public:
    unordered_map <int,vector<int> > preMap;
    unordered_set<int> visiting; //we need this to detect a backedge 

    bool dfs(int current) {
        if(visiting.count(current)) return false; //it is a backedge, therefore a cycle

        if(preMap[current].empty()) return true; //there is no problem at this node ( either it is a leaf or we have already checked it)

        visiting.insert(current);

        for(const int& neighbour: preMap[current]) {//check if there is a problem at each neighbour
        if(!dfs(neighbour)) return false;
            }

        visiting.erase(current); //it is a safe node

        preMap[current].clear(); //we know this is safe and that's why we don't want to check again in the future (this is corresponding to the if.empty condition)
    
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //convert to adj list
        for(int i =0;i < numCourses ; i++ ) {
            preMap[i]  = {};
        }

        for(const auto& prereq: prerequisites) 
        preMap[prereq.at(0)].push_back(prereq.at(1));


        for(int i = 0 ; i < numCourses; i++) { //because the graph can be disconnected, and we need to check for all
            if(!dfs(i))
                return false;
        }

        return true;
    }

};
