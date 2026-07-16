class Solution {
public:
    int dfs_brute(vector<vector<int>>& grid, vector<vector<bool>>& visit, int r, int c, int t) {
        //try all the paths - n2 cells therefore o(4^n2)

        //t : max seen so far on the path
        //bound check
        int n = grid.size();
        if(r < 0 || c < 0 || r >= n || c >= n || visit[r][c]) return INT_MAX; //can't reach from here
        
        if( r == n-1 && c == n-1) return max(t, grid[r][c]); //goal state (take max seen so far)

         visit[r][c] = true;
         t = max(t, grid[r][c]); //max seen so far

        int res = min(min(dfs_brute(grid, visit, r + 1, c, t),
                                     dfs_brute(grid, visit, r - 1, c, t)),
                           min(dfs_brute(grid, visit, r, c + 1, t),
                                    dfs_brute(grid, visit, r, c - 1, t)));
    
        visit[r][c] = false; //backtrack to find a better solution

        return res;
    }


    int swimInWater_brute(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visit(n, vector<bool>(n,false));
        return dfs_brute(grid, visit, 0,0,0);
    }

    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visit, int r , int c, int t) {
        //dfs complexity is n^2 (because of visited array: each cell is visited once)
        if(r < 0 || c < 0 || r >= grid.size() ||
            c >= grid.size() || visit[r][c] || grid[r][c] > t) return false;

        if (r == grid.size() - 1 && c == grid.size() - 1) { //goal state
            return true;
        }

        visit[r][c] = true;
        return dfs(grid, visit, r + 1, c, t) ||
               dfs(grid, visit, r - 1, c, t) ||
               dfs(grid, visit, r, c + 1, t) ||
               dfs(grid, visit, r, c - 1, t);

        //in reachability problems, we don't need to backtrack (because we are not trying all the paths)
        //becuase we know if  I can't reach destination from C, it doenst matter if I come to C from A or B, answer will still be false as from C I can't reach
        //therefore marking C after evaluating its reachability is permanent.
        
    
        //if trying differnt paths and comparing them, then we need to backtrack
    }
    int swimInWater_linear(vector<vector<int>>& grid) {
        //find max and min 
        //we will try all t from min to max;

        //n^4 (n2 can be the maximum range of max-min and n^2 for dfs)
        int n = grid.size();
        vector<vector<bool>> visit(n, vector<bool>(n, false));

        int minH = grid[0][0], maxH = grid[0][0];

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                maxH = max(maxH, grid[row][col]);
                minH = min(minH, grid[row][col]);
            }
        }

        for (int t = minH; t < maxH; t++) {
            if (dfs(grid, visit, 0, 0, t)) {
                return t;
            }
            for (int r = 0; r < n; r++) {
                fill(visit[r].begin(), visit[r].end(), false); //Reset the visited array
            }
        }
        return maxH;
    }

    int swimInWater_binary(vector<vector<int>>& grid) {
        //find max and min 
        //binary search

        //logn*n^2 (n2 can be the maximum range of max-min (but logn^2 for B.S. => logn) and n^2 for dfs)
        int n = grid.size();
        vector<vector<bool>> visit(n, vector<bool>(n, false));

        int minH = grid[0][0], maxH = grid[0][0];

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                maxH = max(maxH, grid[row][col]);
                minH = min(minH, grid[row][col]);
            }
        }

       int l = minH, r = maxH;
       int ans;
       while(l <= r) {
            int m = (l+r) >>1;
            if (dfs(grid, visit, 0, 0, m)) {
                ans = m; //save answer first
                r = m-1;
            }
            else l = m +1;
            
            
            for (int r = 0; r < n; r++) {
                fill(visit[r].begin(), visit[r].end(), false); //Reset the visited array
            }
        }
        return ans;
    }

     int swimInWater(vector<vector<int>>& grid) {

           //dijstra
        //we will track the min-hop distance to reach a cell 
        //greedy rule: Always process the cell with the smallest TimesoFar.
        //(timeSoFar, r, c), where timeSoFar = max height on the path up to (r,c).

        int n = grid.size();
        int m = grid[0].size();
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        vector<vector<int>> dist(n, vector<int>(m, 1e9)); //dist array
        priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>> pq;

        pq.push({grid[0][0],0,0}); //start
        dist[0][0] = grid[0][0]; //max on this path

        while(!pq.empty()){
            
            auto p = pq.top();
            int max_ = p[0];
            int r = p[1];
            int c = p[2];

            pq.pop();

            if(r==n-1 && c==m-1){ //goal
                return max_;
            }

            if(dist[r][c] < max_) continue; //lazy dijstra (remember) - we don't need a visit array

            for(int k = 0;k<4;k++){
                int nr = r+dr[k];
                int nc = c+dc[k];

                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    if(dist[nr][nc] > max(dist[r][c], grid[nr][nc])){
                        dist[nr][nc] = max(dist[r][c],grid[nr][nc]); //update
                        pq.push({dist[nr][nc],nr,nc});
                    }
                }
            }
        }
        return -1;

     }
};
