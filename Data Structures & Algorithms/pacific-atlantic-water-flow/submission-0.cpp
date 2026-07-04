class Solution {
public:
    int rows, cols;
    bool atlantic, pacific;
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

    void dfs_bruteforce(vector<vector<int>>& heights, int r, int c, int prevHeight ) {
        // (m*n * 4^(m+n) for each cell, 4 recursive calls
        if(r < 0 || c < 0) {
            pacific = true; 
            return;
        }

        if(r >= rows || c >= cols) {
            atlantic = true; 
            return;
        }

        if(heights[r][c] > prevHeight) return; //can't flow from previous state to this state

        //valid state; 
        int temp = heights[r][c]; //store this to reset when we backtrack
        heights[r][c] = INT_MAX; //to make it unreachable (like in visited array)
        for(auto x: directions) {
            dfs_bruteforce(heights, r + x[0], c + x[1], temp);

            if(pacific && atlantic) break; //this is for optimisation
            //if we know it reaches both, we don't need to explore further directions
        }

        heights[r][c] = temp; //backtrack and reset
    }

    vector<vector<int>> pacificAtlantic_bruteforce(vector<vector<int>>& heights) {
        //bruteforce - check from each cell, if you reach out of bound
        vector<vector<int>> res; //answer
        rows = heights.size();
        cols = heights[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                atlantic = false; 
                pacific = false;
                dfs_bruteforce(heights,r,c,INT_MAX);
                if(pacific && atlantic) //reaching both
                    res.push_back({r,c});
            }
        }

        return res; 
    }

void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& ocean){
        ocean[r][c] = true;

        for(auto dir: directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            //first check bounds and then the height condition
                if(nr>=0 && nr <rows && nc >=0 && nc < cols && !ocean[nr][nc] && heights[r][c]<=heights[nr][nc]) 
                    dfs(nr,nc,heights,ocean);
            
        }
    }
 
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res; //answer
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pac(rows, vector<bool>(cols,false));
        vector<vector<bool>> atl(rows, vector<bool>(cols,false));

        for(int c = 0; c < cols; c++) { 
           dfs(0,c,heights,pac); //first row
           dfs(rows-1,c,heights,atl); //last row
        }
        for(int r = 0; r < rows; r++) {
           dfs(r,0,heights,pac); //first col
           dfs(r,cols-1,heights,atl); //last col
        }

        //if that cell is reachable from both
        for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) { 
            if(atl[r][c] && pac[r][c])
                    res.push_back({r,c});
        }
         }
        return res;
    }
};
