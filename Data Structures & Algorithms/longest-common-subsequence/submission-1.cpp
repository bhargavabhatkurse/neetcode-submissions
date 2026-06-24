class Solution {
public: 
    vector<vector<int>> dp;
    int rec_forward(string text1, string text2, int i, int j) {
        //forward: 
        //here, dp[i][j] means consider next as [i....] and [j....]; (from i to end and from j to end)
        if(i == text1.size() || j == text2.size()) return 0; //base (0 lcs when one of the strings has no characters)

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]) return dp[i][j] = 1 + rec_forward(text1,text2,i+1,j+1);
        else return dp[i][j] = max(rec_forward(text1,text2,i+1,j),rec_forward(text1,text2,i,j+1));
    }

    int rec_backward(string text1, string text2, int i, int j) {
        //forward: 
        //here, dp[i][j] means consider from as [0.....i] and [0....j]; from start to i and from start to j;
        if(i < 0 || j < 0) return 0; //base

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]) return dp[i][j] = 1 + rec_backward(text1,text2,i-1,j-1);
        else return dp[i][j] = max(rec_backward(text1,text2,i-1,j),rec_backward(text1,text2,i,j-1));
    }

    int longestCommonSubsequence_forTopDown(string text1, string text2) {
        dp = vector<vector<int>>(text1.size(),vector<int>(text2.size(),-1)); //i and j both from 0 to n-1
        
        //return rec(text1,text2,0,0); for forward
        //return rec(text1,text2,text1.size()-1,text2.size()-1); //for backward
    }

    int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    dp = vector<vector<int>>(n+1,vector<int>(m+1,0));
    
    //forward 
    //dp[i][j] -> from i to end and from j to end
    //If your recursive state moves forward (i+1, j+1), then bottom-up usually fills backward.
     //entire last column n and m should be 0. Therefore n+1, m+1 dp was created
                //         j
                //     0   1   2
                //     +-----------
                // 0   | ?   ?   0
                // 1   | ?   ?   0
                // 2   | ?   ?   0
                // 3   | 0   0   0
    
    for(int i = n - 1; i >=0; i--)
    for(int j = m - 1; j >= 0; j--)
    if(text1[i] == text2[j])
    dp[i][j] = 1 + dp[i+1][j+1];
    else dp[i][j] = max( dp[i+1][j], dp[i][j+1]);

    //return dp[0][0]; //lcs from start to end of both


    //backward
    //dp[i][j] = 1 + dp[i-1][j-1]: dp means from 0 to i and from 0 to j
    int bias = 1; //becuase I want dp[0][*] = 0 and also dp[*][0] = 0; and start from 1;
    dp = vector<vector<int>>(n+1,vector<int>(m+1,0));
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
    if(text1[i] == text2[j])
    dp[i+bias][j+bias] = 1 + dp[i-1 + bias][j-1 + bias];
    else dp[i+bias][j+bias] = max( dp[i-1 + bias][j+ bias], dp[i+ bias][j-1 + bias]);
    
    return dp[n][m];

    //cleaner
    // for(int i = 0; i < n; i++)
    // for(int j = 0; j < m; j++)
    // if(text1[i] == text2[j])
    // dp[i+1][j+1] = 1 + dp[i][j];
    // else dp[i+1][j+1] = max( dp[i][j+1], dp[i+1][j]);
    
    // return dp[n][m];
    }
};
