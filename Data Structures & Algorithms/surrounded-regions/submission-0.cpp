class Solution {
    int ROWS, COLS;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0},
                                         {0, 1}, {0, -1}};

public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        capture(board);

        //reseting the border 0s and making the surrounded 0s as X
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }
    }

private:
    void capture(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (r == 0 || r == ROWS - 1 ||  //check only border cells
                    c == 0 || c == COLS - 1 &&
                    board[r][c] == 'O') { 
                    q.push({r, c});
                }
            }
        }
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (board[r][c] == 'O') {
                board[r][c] = 'T';
                for (auto& direction : directions) {
                    int nr = r + direction.first;
                    int nc = c + direction.second;
                    if (nr >= 0 && nr < ROWS &&
                        nc >= 0 && nc < COLS) {
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
};