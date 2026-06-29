class Solution {
public:
    int minDistance_bottomUp(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int> >table(m+1,vector<int>(n+1));

        for(int j = 0;j<=n;j++) {
            table[0][j] = j;
        }

        for(int i = 0;i<=m;i++) {
            table[i][0] = i;
        }

        for(int i = 1;i<=m;i++)
        for(int j = 1;j<=n;j++)
            if(word1[i-1] == word2[j-1]) table[i][j] = table[i-1][j-1];
            else table[i][j] = 1 + min(min(table[i][j-1],table[i-1][j-1]),table[i-1][j]);


        return table[m][n];
    }
    vector<vector<int>> dp;

    int rec(string s, string t, int i, int j) {
        if(i == s.size()) return t.size()-j;
        
        if(j == t.size()) return s.size()-i;

        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = rec(s,t,i+1,j+1);

        else return dp[i][j] = 1+min(min(rec(s,t,i+1,j),rec(s,t,i+1,j+1)),rec(s,t,i,j+1));

    }
    int minDistance(string word1, string word2) {
        dp.assign(word1.size(),vector<int>(word2.size(),-1));
        return rec(word1, word2, 0,0);
        
    }
};
