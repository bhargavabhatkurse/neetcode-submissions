class Solution {
public:

    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>> q;
        unordered_map<string,bool> vis;
        q.push({"0000",0});
        vis["0000"] = true;
        
        unordered_set<string> dead(deadends.begin(), deadends.end());
        
        while(!q.empty()) {
            auto [s,moves] = q.front();
            q.pop();
            
            if(s == target) return moves;

            if(dead.count(s)) continue; //blocked

            //children
            for(int i = 0; i < 4;i++) {
               string next = s;
               next[i] = (next[i] - '0' + 1) % 10 + '0';
                if (!vis[next] && !dead.count(next)) {
                    vis[next] = true;
                    q.push({next, moves + 1});
                }

               next = s;
               next[i] = (next[i] - '0' + 9) % 10 + '0';
                if (!vis[next] && !dead.count(next)) {
                    vis[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
};