class Solution {
public:
    bool valid(string s) {
        int l =0, r = s.size()-1;
        while(l < r) {
            if(s[l] == s[r]){
                l++;
                r--;
            }
            else return false;
        }
        return true;

    }
    bool validPalindrome(string s) {
        if(valid(s)) return true;

        //try removing one character
        for(int i =0; i < s.size();i++) {
            string substring = s.substr(0,i) + s.substr(i+1); //skip the ith character
            if(valid(substring)) return true;
        }
        return false; //not valid even after deleting exactly one character
    }
};