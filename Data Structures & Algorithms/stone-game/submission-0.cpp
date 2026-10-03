class Solution {
public:
    vector<vector<int>> dp;
    int win(vector<int>& piles, int l, int r) {
        if(l > r) return 0; //no more stones
        if(dp[l][r] != -1) return dp[l][r];
        bool even = (r-l)%2 == 0; //odd if alices's turn
        
        //bobs choice(if range is odd) is taken as negative (after bob choice, the range will again become even)
        int left = even ? piles[l] : -piles[l];
        int right = even ? piles[r]: -piles[r];

        return dp[l][r] = max(left + win(piles,l+1, r), right + win(piles,l, r-1));

    }
    bool stoneGame(vector<int>& piles) {
        dp.resize(piles.size(),vector<int>(piles.size(),-1));
        return win(piles,0,piles.size()-1) > 0? true: false;
    }
};