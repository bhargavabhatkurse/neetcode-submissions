class Solution {
public:
vector<int> dp;
    int rec(string& s, int i) {
        int res; 
        
        if(i >= s.size()) return i==s.size(); //1 if exactly s.size() or 0 (because it skipped)
        
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];

        //if(s[i+1] == '0') res = rec(s,i+2); //no need to do this
        
        res = rec(s,i+1); //check the next (if the next char is 0, it will return 0 as starting 0 can't be decoded)

        int x = stoi(s.substr(i, 2));
        if(x >= 10 && x <=26 ) //10 because valid 2 digit should start from 10, otherwise we might get 01,02 etc
            res += rec(s,i+2);
        

        return dp[i] = res;
    }

    int numDecodings(string s) {
        dp.assign(s.size(),-1);
        return rec(s,0);
    }
};
