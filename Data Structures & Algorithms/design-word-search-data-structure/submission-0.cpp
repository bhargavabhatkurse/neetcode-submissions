class TrieNode {
    public: 
    //they have to public: otherwise can't be accessed
    vector<TrieNode*> children; //26 letters 
    bool endofword; 

    TrieNode(): children(26,nullptr), endofword(false) {}
};

class WordDictionary {
     TrieNode* root;
public:
    WordDictionary() {
         root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a'; //index
            if (cur->children[i] == nullptr) {
                cur->children[i] = new TrieNode(); //create new character
            }
            cur = cur->children[i];
        }   
         cur->endofword = true; //mark the last character as endofword
    }
    
    int dfs(string word, int idx,TrieNode* root) {
        
        TrieNode* cur = root;
        for(int i=idx; i < word.size();i++) {
            char c = word[i];
            if(c == '.') {
                for(auto child: cur->children) {
                    if(child && dfs(word,i+1, child)) 
                        return true; 
                    }
                    return false;
            }
            else //matched
                {
                if (cur->children[c-'a'] == nullptr) {
                        return false;
                }
                cur = cur->children[c-'a'];
                }
       
        }
         return cur->endofword;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }
};
