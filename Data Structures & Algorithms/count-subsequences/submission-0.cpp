class Solution {
public:
    vector<vector<int>> dp;
    int rec(string s, string t, int i , int j) {
        if(j == t.size()) return 1; //found a val solution

        if(i == s.size()) return 0; //if s ends but t doesnt end (not a soln)

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = rec(s,t,i+1,j) + rec(s, t, i+1, j+1); //if match, we also need to explore by skipping the matched character
        else return dp[i][j] = rec(s,t,i+1,j);
    }

    int numDistinct(string s, string t) {
        dp = vector<vector<int>>(s.size()+1, vector<int>(t.size()+1,-1));
        return rec(s,t,0,0);
    }
};
