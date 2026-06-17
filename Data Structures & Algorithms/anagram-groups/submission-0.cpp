class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //O(m*nlogn)
        // unordered_map<string, vector<string>> res;
        // for(const auto& s: strs) {
        //     string sortedS = s;
        //     sort(sortedS.begin(),sortedS.end());
        //     res[sortedS].push_back(s);
        // }
        // vector<vector<string>> result;
        // for(auto& p: res) {
        //     result.push_back(p.second);
        // }
        // return result;

       //o(m*n) solution --avoid sorting

       unordered_map<string, vector<string>> res;
       for(const auto& s: strs) {
        vector<int> count(26,0);
        for(char c: s) {
             count[c -'a']++; //important to be in the range 0 to 26
        //make the entire count array as 1 key: 
        }
        string key = to_string(count[0]);
        for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s);
       }
       
       vector<vector<string>> result;
       for(auto& item: res) {
        result.push_back(item.second);
       }
    return result;
    }
};
