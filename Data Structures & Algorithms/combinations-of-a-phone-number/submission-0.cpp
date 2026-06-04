class Solution {
    vector<string> results;
    string s;
    unordered_map<char, vector<char>> Map;
    void soln(string digits);
public:
    vector<string> letterCombinations(string digits) {

        results.clear();
        s.clear();

       if (digits.empty()) return results; //to handle the case

       Map = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
        soln(digits,0);
        return results;
    }

    void soln(string digits,int index) {
        if(index == digits.length()) {results.push_back(s); return;}

            for (char c : Map[digits[index]]) {
            s.push_back(c);
            soln(digits,index+1);
            s.pop_back();

        }

    }
};
