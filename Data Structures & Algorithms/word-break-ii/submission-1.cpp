class Solution {
public:

    void rec(string s,set<string>& words, vector<string>& path, vector<string>& ans) {
    if(s.empty()) {
        string sentence = "";

        for(string word : path)
            sentence += word + " ";

        sentence.pop_back();

        ans.push_back(sentence);

        return;
    }

    for(int i = 1; i <= s.size(); i++) { //remember to start from 1 )starts from 1 because the prefix must contain at least one character)

        string word = s.substr(0, i);

        if(words.count(word)) { //valid word

            path.push_back(word);

            rec(s.substr(i),words, path, ans); //find all solutions

            path.pop_back();   // backtrack
        }
    }
}

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        vector<string> path;
        set<string>word(wordDict.begin(),wordDict.end());
        rec(s,word,path,ans);
        return ans;
    }
};