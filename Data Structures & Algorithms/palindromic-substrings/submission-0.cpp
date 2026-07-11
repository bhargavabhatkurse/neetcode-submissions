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
    int countSubstrings(string s) {
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
    }
};
