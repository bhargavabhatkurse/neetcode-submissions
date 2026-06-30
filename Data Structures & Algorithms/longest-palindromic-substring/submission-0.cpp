class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int mx = 0;
        for(int i = 0; i < s.size();i++) 
        for(int j = i; j < s.size();j++) {
            string x = s.substr(i,j-i+1);
            string xr = x;
            reverse(xr.begin(),xr.end());
            if(x == xr && mx < x.size()) {
                ans = x;
                mx = x.size();
            }
        }
        return ans;
    }
};
