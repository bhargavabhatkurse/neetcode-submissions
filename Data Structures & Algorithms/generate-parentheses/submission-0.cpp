class Solution {
public:
    vector<string> res;
    void rec(int n, string& ans, int open,int closed) {
        
        if(open == closed && open == n) {
            res.push_back(ans);
            return;
        }
        

        if(open < n) {
        ans.push_back('(');
        rec(n, ans,open+1, closed);
        ans.pop_back();
        }

        if(closed < open) {
        ans.push_back(')');
        rec(n, ans,open, closed+1);
        ans.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        //bruteforce will take n(to check if valid using stack) * 2^2n ( to generate)
        string ans; 
        rec(n,ans,0,0);
        return res;

    }
};
