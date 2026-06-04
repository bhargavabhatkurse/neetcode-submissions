class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;  //Use BFS for such questions
        int fresh = 0;
        int time = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                //if fresh, count the fresh
                if (grid[r][c] == 1) {
                    fresh++;
                }
                if (grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }

        while (fresh > 0 && !q.empty()) {

            time++;
            
            int length = q.size();
            for (int i = 0; i < length; i++) {
                auto curr = q.front();
                q.pop();
                
                int r = curr.first;
                int c = curr.second;

                for (const auto& dir : directions) {
                    int row = r + dir.first;
                    int col = c + dir.second;
                    if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && //check bounds
                                                grid[row][col] == 1)//if it is fresh
                        { 
                            grid[row][col] = 2; //make it rotten
                            q.push({row, col});  //push the rotten
                            fresh--;
                        }
                }
            }
        }
        return fresh == 0 ? time : -1; //if some fresh are left out, return -1
    }
};