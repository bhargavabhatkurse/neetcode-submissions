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
    bool stoneGame_(vector<int>& piles) {
        //top down
        dp.resize(piles.size(),vector<int>(piles.size(),-1));
        return win(piles,0,piles.size()-1) > 0? true: false;
    }

     bool stoneGame(vector<int>& piles) { 
        //bottom up
        int n = piles.size();
        dp.resize(n+1,vector<int>(n+1,0));
        
        for(int l = n-1; l >=0; l--) {
            for(int r = l; r <n;r++) { //r = l so that r >= l
                    bool even = (r-l)%2 == 0; //odd if alices's turn
                    int left = even ? piles[l] : -piles[l];
                    int right = even ? piles[r]: -piles[r];
                    
                    //if interval contains only 1 element
                    // Otherwise, l+1 > r and r-1 < l, so the recurrence would refer
                    // to an empty interval (and r-1 can become -1).
                    if (l == r) { //otherwise in 'else' block, r-1 will become invalid
                    dp[l][r] = left;
                    continue;
                    } 
                    //else
                    dp[l][r] = max(left + dp[l+1][r], right + dp[l][r-1]);
            }
        }
        
        return dp[0][n-1] > 0;

     }

};