class Solution {
public:
    bool isPalindrome(string s) {
        string p1 = "";
        string p2 = "";

        for(char c: s)
        if(isalnum(c)) {    //only keeping alpha-numeric
            p1.insert(0,1,(char)tolower(c));  //ignoring the case
            p2.push_back((char)tolower(c));
        }
        else continue;
        
    
        if(p1 == p2) return true;
        else return false;
    }
};
