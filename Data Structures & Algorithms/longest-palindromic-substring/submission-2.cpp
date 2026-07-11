class Solution {
public:
    string longestPalindrome_bruteforce(string s) {
        //on3 bruteforce (checking pallindrome itself is o(n))
        string ans = "";
        int mx = 0;
        // for(int i = 0; i < s.size();i++) 
        // for(int j = i; j < s.size();j++) {
        //     string x = s.substr(i,j-i+1);
        //     string xr = x;
        //     reverse(xr.begin(),xr.end());
        //     if(x == xr && mx < x.size()) {
        //         ans = x;
        //         mx = x.size();
        //     }
        // }

        //without using inbuilt functions
        for(int i = 0; i < s.size();i++) {
        for(int j = i; j < s.size();j++) {
            int l = i, r = j;
            while(l < r && s[l] == s[r]) { //pallindrome
                l++;
                r--;
            }

            if( l >= r && mx < (j-i+1)) { //if pallindrome and greater than current max substring
                // l>=r not l > r for odd length pallindrome
                ans = s.substr(i, j-i+1);
                mx = j-i+1;
            }
        }
        }
        return ans;
    }

    string longestPalindrome_2(string s) {
        //cant do sliding window: sliding window needs some monotonic property

        //two pointer

        //we need to check odd and even both - because otherwise if the pallindrome is even and we check only odd, we will never find the even pallindrome like abba
        int reslen = 0;
        int res; //index of the pallindrome
        for(int i = 0; i < s.size();i++) {
            //odd pallindrome
            int l = i,r = i;
            while(l>=0 && r < s.size() && s[l] == s[r]) {
            if(r-l+1 > reslen) { //update maximum
                res = l; //start of the pallindrome
                reslen = r-l+1;
            }

            //expand outwords
            l--;
            r++;
            }
            //even length pallindrome
            l = i;
            r =i+1;
            
            while(l>=0 && r < s.size() && s[l] == s[r]) {
            if(r-l+1 > reslen) { //update maximum
                res = l; //start of the pallindrome
                reslen = r-l+1;
            }
            l--;
            r++;
            }
        }
        return s.substr(res, reslen);
    }


    string longestPalindrome(string s) {
        //cant do sliding window: sliding window needs some monotonic property

        //DP - we should remember if the substring is pallindrome, we should not check it again and again
        //dp[i][j] = true if the substring s[i..j] is a palindrome.
        //dp[i][j]=(s[i]==s[j])∧dp[i+1][j−1] (the first and last character should match and everything between should match)
      
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int res;
        int reslen = 0;
        
        for(int i = n-1; i>=0;i--) {//forward dp
          for(int j = i; j < n;j++) {//check every i...j (3...4, 3...5, 3...6) [j < i doesnt make sense eg: 4.....3]
                 if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) { //if len = 1,2,3 only matching the first and last character is enough (special case)
                 dp[i][j] = true;
                
                //update max
                    if(j-i+1 > reslen) {
                        reslen = j-i+1;
                        res = i; //starting index
                    }
                 }
    }
}
        
        
        return s.substr(res, reslen);
    }

};
