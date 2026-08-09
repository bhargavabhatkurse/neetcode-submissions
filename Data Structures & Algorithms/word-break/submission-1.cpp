class Solution {
public:
    unordered_map<string,bool> dp;
    bool rec(string s, vector<string>& wordDict) {

        if(find(wordDict.begin(),wordDict.end(),s) != wordDict.end()) return true;
        
         if(dp.find(s) != dp.end())
            return dp[s];

        bool flag = false;
        for(int i =1; i < s.size();i++) { //remember to start from 1, to break it atleast into 1 and rest (otherwise infinite recursion)
        bool left = rec(s.substr(0,i),wordDict);
        if(left) //if left is the word
            flag = rec(s.substr(i),wordDict);
        
        if(flag) break;
        }
        
        return dp[s] = flag;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        return rec(s,wordDict);
    }
};
