class Solution {
public:
    bool rec(string& s1, string& s2, string& s3, int i, int j, int k) {
        //bruteforce - o(2^m+n)
        if(k == s3.size()) { 
            return (i==s1.size()) && (j == s2.size()); //we need to check this because reaching the end of s3 doesnt always mean we have used all the characters from s1 and s2
        }
        if(i < s1.size() && s1[i] == s3[k]) {
            if(rec(s1,s2,s3,i+1,j,k+1)) //only if the path exists 
                return true;
            }

        //mistake: return rec(s1,s2,s3,i+1,j,k+1) becuse when both s1 and s2 are matching with s3,  if we match character from s1 first and it doesnt return a result, we should not directly return false, we should try and match s2's character also
        
        //otherwise backtrack and make choice from s2
        if(j < s2.size() && s2[j] == s3[k]){
             if(rec(s1,s2,s3,i,j+1,k+1))
              return true;
        }

        return false; //if no path leads to the end;
    }

    vector<vector<int>> dp; //dp[i][j] stores can I use remaining of s1 and remaining of s2 to form s3
    //we don't need to store k as k = i + j (always)
    bool rec_topdown(string& s1, string& s2, string& s3, int i, int j, int k) {
        
        if(k == s3.size()) { 
            return (i==s1.size()) && (j == s2.size()); //we need to check this because reaching the end of s3 doesnt always mean we have used all the characters from s1 and s2
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool res = false; // initially
        if(i < s1.size() && s1[i] == s3[k]) {
            res = rec_topdown(s1,s2,s3,i+1,j,k+1); //check if path exists
            }

        //mistake: return rec(s1,s2,s3,i+1,j,k+1) becuse when both s1 and s2 are matching with s3,  if we match character from s1 first and it doesnt return a result, we should not directly return false, we should try and match s2's character also
        
        //otherwise backtrack and make choice from s2
        if(j < s2.size() && s2[j] == s3[k]){
             res = rec_topdown(s1,s2,s3,i,j+1,k+1); //check if path exists
        }
        dp[i][j] = res;
            return res;
    }

    //top down: 
    bool isInterleave_topdown(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
         if (m + n != s3.length()) 
            return false;

        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));

        //becuase i can go till m and remaining will be empty string for s1 but string s2 can still continue
        //thats why i = 0 to m therefore m+1
        return rec_topdown(s1,s2,s3,0,0,0);
    }


    vector<vector<bool>> d_p;
    bool isInterleave(string s1, string s2, string s3) {
    //always draw tree for dp;
    int m = s1.size(), n = s2.size();
         if (m + n != s3.length()) 
            return false;

    d_p = vector<vector<bool>>(m + 1, vector<bool>(n + 1, false));

    d_p[m][n] = true; //this is same as i==m and j==n base condition of top down

    //draw 2D table to visualise
    //dp[i][j] depends on right and down : therefore backward
    for(int i = m; i >= 0; i --)
    for(int j = n; j >= 0; j --) {
        //possible with down?
        if(i < m && s1[i] == s3[i+j] && d_p[i+1][j]) d_p[i][j] = true;
        //possile with right?
        if(j < n && s2[j] == s3[i+j] && d_p[i][j+1]) d_p[i][j] = true;

        //we need to check both ifs (therefore its not if else)
    }

    for(auto x: d_p) {
    for(auto i: x) cout<<i<<" ";
    cout<<endl;
    }
    return d_p[0][0];
    }
};
