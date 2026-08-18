class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //indegree == n-1 and outdegree == 0
        unordered_map<int, int> indegree;
        unordered_map<int, int> outdegree;

        for(auto t: trust) {
            indegree[t[1]]++;
            outdegree[t[0]]++;
        } 

        for(int i =1; i <= n; i++) {
            if(indegree[i] == n-1 && outdegree[i] == 0) return i;
        }
        
        return -1;
    }
};