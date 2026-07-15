class TrieNode {
    public: 
    //they have to public: otherwise can't be accessed
    TrieNode* children[26]; //26 letters 
    bool endofword; 

    TrieNode() {
    for(int i = 0; i < 26; i++) {
        children[i] = nullptr;
    }
    endofword = false;
    }
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
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
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a'; //index
            if (cur->children[i] == nullptr) {
                return false; //not found
            }
            cur = cur->children[i];
        }
        return cur->endofword; //check if its really the end of the word
    }
    
    bool startsWith(string prefix) {
         TrieNode* cur = root;
        for (char c : prefix) {
            int i = c - 'a'; //index
            if (cur->children[i] == nullptr) {
                return false; //not found
            }
            cur = cur->children[i];
        }
        return true; //the difference here is after prefix is over, return true (we don't care if the word has finished or not)
    }
};
