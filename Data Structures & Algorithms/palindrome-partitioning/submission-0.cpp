class Solution {
    vector<vector<string>> results;
    vector<string> temp;

public:
    bool isPalindrome(const string &s, int left, int right) {
    
    while (left < right) {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

    vector<vector<string>> partition(string s) {
        soln(s,0);
        return results;
    }

    void soln(string s,int index) {

        if(index == s.length()) {results.push_back(temp);return;}

        for(int j = index;j<s.length();j++) {
            if(isPalindrome(s,index,j)) {
                temp.push_back(s.substr(index,j- index + 1));
                soln(s,j+1);
                temp.pop_back();
            }
        }

    }
};
