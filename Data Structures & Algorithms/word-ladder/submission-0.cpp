class Solution {
public:
    int bfs(string beginWord, string endWord, set<string>& wordList) {
        //find the minimum length of the sequence
        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        visited.insert(beginWord);
        int level = 1; // level order

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string word = q.front();
                q.pop();

                if (word == endWord)
                    return level;

                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {

                        word[i] = c;

                        if (wordList.count(word) && !visited.count(word)) {
                            // word is a neighbour
                            q.push(word);
                            visited.insert(word);
                        }
                    }
                    word[i] = original;
                }
            }
            level++;
        }
        return 0; //cant reach
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> words(wordList.begin(),wordList.end());
        return bfs(beginWord,endWord,words); 
    }
};
