class Solution {
    int row, col;
    vector<vector<bool>> visited;
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();

        visited  = vector<vector<bool> >(row,vector<bool>(col,false));

        for(int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (soln(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

     bool soln(vector<vector<char>>& board, string word, int r, int c, int i) {
        if (i == word.length()) {
            return true;
        }

        if (r < 0 || c < 0 || r >= row || c >= col ||
            board[r][c] != word[i] || visited[r][c]) {
            return false;
        }

        visited[r][c] = true;
        bool res = soln(board, word, r + 1, c, i + 1) ||
                   soln(board, word, r - 1, c, i + 1) ||
                   soln(board, word, r, c + 1, i + 1) ||
                   soln(board, word, r, c - 1, i + 1);
        visited[r][c] = false;

        return res;
    }


};
