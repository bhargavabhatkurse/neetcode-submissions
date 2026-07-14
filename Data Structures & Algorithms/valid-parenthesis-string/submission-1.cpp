class Solution {
public:
    int valid(string s) {
        
        int open = 0,close =0;
        for (char c : s) {
            if(c == '*') return false;
            (c == '(') ? open++ : close++;
            if (open < close) return false; //close > open, invalid
        }
        
        return open == close; //no of both are equal
    }

    bool brute(string s) {
        int n = s.size();
        if(valid(s)) return true;
        
        for(int i =0; i < s.size();i++) {
            if(s[i] == '*')
            {   //split
            string left  = s.substr(0, i);
            string right = s.substr(i + 1);
     
     
                bool b1 = brute(left+"(" +right);
                bool b2 = brute(left+right);
                bool b3 = brute(left+")"+right);
            
                return b1 || b2 || b3;
            }
        }

        return false;
    }

    bool checkValidString_brute(string s) {
        //this method works but difficult to convert  to DP
        return brute(s);
    }

    vector<vector<int>> dp;
    bool rec(string s, int i, int open) { //ith character current
        if(open < 0) return false;
        if(i == s.size()) return open == 0; //all close and opens match

        if(dp[i][open] != -1) return dp[i][open];
        if(s[i] == '(') {
            return rec(s, i+1, open +1);
        }
        else if(s[i] == ')') return dp[i][open] = rec(s,i+1,open -1);
        else { //* character
            int result = rec(s,i+1,open+1) || rec(s,i+1,open) || rec(s,i+1,open -1);
            return dp[i][open] = result;
        }
    }


    bool checkValidString(string s) {
        //top down
        int n = s.size();
        dp.assign(n, vector<int>(n+1,-1)); //all characters can become open, therefore max open is o to n
        return rec(s,0,0);

    }
};
