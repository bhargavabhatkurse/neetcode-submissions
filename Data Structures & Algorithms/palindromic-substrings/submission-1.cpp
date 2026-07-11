class Solution {
public:
    int countSubstrings1(string s) {
        //bruteforce - n^3

        //without using inbuilt functions
        int count =0;
        for(int i = 0; i < s.size();i++) {
        for(int j = i; j < s.size();j++) {
            int l = i, r = j;
            while(l < r && s[l] == s[r]) { //pallindrome
                l++;
                r--;
            }

            if( l >= r) { //if pallindrome and greater than current max substring
               count++;
            }
        }
        }
        return count;
    }
    int countSubstrings2(string s) {
     //cant do sliding window: sliding window needs some monotonic property

        //two pointer

        //we need to check odd and even both - because otherwise if the pallindrome is even and we check only odd, we will never find the even pallindrome like abba
        int count = 0;
        for(int i = 0; i < s.size();i++) {
            //odd pallindrome
            int l = i,r = i;
            while(l>=0 && r < s.size() && s[l] == s[r]) {
                    count++;

            //expand outwords
            l--;
            r++;
            }
            
            //even length pallindrome
            l = i;
            r =i+1;
            
            while(l>=0 && r < s.size() && s[l] == s[r]) {
                count++;
            l--;
            r++;
            }
        }
        return count;

        //optimisation will be to factor out the counting part and pass l and r as parameters to a helping funciton
    }
    
    
    int countSubstrings(string s) {
    //cant do sliding window: sliding window needs some monotonic property

        //DP - we should remember if the substring is pallindrome, we should not check it again and again
        //dp[i][j] = true if the substring s[i..j] is a palindrome.
        //dp[i][j]=(s[i]==s[j])∧dp[i+1][j−1] (the first and last character should match and everything between should match)
      
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int count =0;
        
        for(int i = n-1; i>=0;i--) {//forward dp
            for(int j = i; j < n;j++) {//check every i...j (3...4, 3...5, 3...6) [j < i doesnt make sense eg: 4.....3]
                 if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) { //if len = 1,2,3 only matching the first and last character is enough (special case)
                 dp[i][j] = true;
                
                    count++;
                 }
            }
        }

        return count;
    }


};
