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

    string longestPalindrome(string s) {
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


};
