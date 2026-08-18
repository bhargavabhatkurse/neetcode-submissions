class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m;
         
        for (int i = 0; i < order.size(); ++i)
            m[order[i]] = i;

        auto compare = [&](const string &a, const string &b) {
            for(int i = 0; i < min(a.size(),b.size());i++) {
                if(a[i] != b[i]) {
                    return m[a[i]] < m[b[i]];
                }
            }

            return a.size() < b.size(); //if one is prefix of other
        };

        return is_sorted(words.begin(),words.end(),compare);
    }
};