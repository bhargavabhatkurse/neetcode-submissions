class Solution {
public:
    vector<vector<int>> dp;
    int rec(string s, string t, int i , int j) {
        if(j == t.size()) return 1; //found a val solution

        if(i == s.size()) return 0; //if s ends but t doesnt end (not a soln)

        // if(dp[i][j] != -1) return dp[i][j];

        // if(s[i] == t[j]) return dp[i][j] = rec(s,t,i+1,j) + rec(s, t, i+1, j+1); //if match, we also need to explore by skipping the matched character
        // else return dp[i][j] = rec(s,t,i+1,j);

        //another way of writing:
        int res = rec(s,t,i+1,j);//skip the character

        if(s[i] == t[j]) res += rec(s,t,i+1,j+1); //take it only if it matches

        dp[i][j] = res;
        return res;
    }

    int numDistinct__topdown(string s, string t) {
        if(t.length() > s.length()) return 0;
        //dp = vector<vector<int>>(s.size()+1, vector<int>(t.size()+1,-1));
        dp.assign(s.size()+1, vector<int>(t.size()+1,-1));
        return rec(s,t,0,0);
    }

    int numDistinct1(string s, string t) {
       //bottom up: m*n space and time
        int m = s.size(), n = t.size();
        if(n > m) return 0;
        dp.assign(m+1, vector<int>(n+1,-1));

        //dp[i][j] = number of ways to form t[j:] using s[i:]

        //same as top down base cases
        //base case 1: 
        for(int i = 0; i <= m; i++) dp[i][n] = 1; //always possible if t is empty

         //base case 2: 
        for(int i = 0; i < n; i++) dp[m][i] = 0; //not possible if s is empty

        for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
        dp[i][j] = dp[i+1][j];//skip the character
        if(s[i] == t[j]) dp[i][j] += dp[i+1][j+1];; //take it only if it matches
        }
        }


        for(auto i : dp) {
            for(int j : i)
            cout<<j<<" ";
        cout<<endl;
        }

        return dp[0][0]; 



    }

    int numDistinct(string s, string t) {
       //bottom up:Space optimised
       //we only need the next row i+1
       //recursion both subparts require next row
        
        int m = s.size(), n = t.size();
        if(n > m) return 0;
        vector<int> dp_curr(n+1,0); //curr_row
        vector<int> dp_next(n+1,0); //below row

        dp_curr[n] = dp_next[n] = 1;

        for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
        
        dp_curr[j] = dp_next[j];//skip the character
        if(s[i] == t[j]) dp_curr[j] += dp_next[j+1]; //take it only if it matches
        }
        dp_next = dp_curr;
        }
        
        return dp_curr[0]; 

    }
    




};
