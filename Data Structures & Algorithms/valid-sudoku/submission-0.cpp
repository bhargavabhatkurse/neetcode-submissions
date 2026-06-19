class Solution {
public:
    bool isValidSudoku_hash(vector<vector<char>>& board) {
    //using hashset
    unordered_map<int, unordered_set<char>> row, col;
    //cant' do this because there is no hash for pair<int, int> we have to define it ourselves
    //unordered_map<pair<int,int>, unordered_set<char>> box; 

    map<pair<int,int>, unordered_set<char>> box; 

    for(int r = 0; r < 9; r++)
        for(int c = 0; c < 9; c++) {
            if(board[r][c] == '.') continue;
            
            pair<int,int> box_key = {r/3, c/3};
            if(row[r].count(board[r][c]) || col[c].count(board[r][c]) || box[box_key].count(board[r][c])) return false;

            row[r].insert(board[r][c]);
            col[c].insert(board[r][c]);
            box[box_key].insert(board[r][c]);
            
        }   
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
    //using bit_mask
    int row[9] = {0};
    int col[9] = {0};
    int box[9] = {0};

    for(int r = 0; r < 9; r++)
        for(int c = 0; c < 9; c++) {
            if(board[r][c] == '.') continue;
            int val = int(board[r][c]) - 1; //convert value to a bit index
            int mask = 1 << val;
            int box_key = (r/3)*3 + c/3; //important
            if(row[r]&mask || col[c]&mask || box[box_key]&mask) return false;

            row[r] |= mask;
            col[c] |= mask;
            box[box_key] |= mask;
            
        }   
        return true;
    }
};
