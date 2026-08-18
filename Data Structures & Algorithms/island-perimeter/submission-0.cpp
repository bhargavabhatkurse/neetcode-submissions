class Solution {
public:
    vector<vector<bool>> visited;
    int rows, cols;

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0) { //if it hits bounds, it is a perimeter
            return 1;
        }
        if (visited[i][j]) {
            return 0;
        }

        visited[i][j] = true;
        return dfs(grid, i, j + 1) + dfs(grid, i + 1, j) +
               dfs(grid, i, j - 1) + dfs(grid, i - 1, j);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j);
                }
            }
        }
        return 0;
    }
};