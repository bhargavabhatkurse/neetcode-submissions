class TrieNode {
    //check both submissions

    // 1) using array of pointers
    
    // This one
    // 2) using hashmap

    public: 
    //they have to public: otherwise can't be accessed
    unordered_map<char,TrieNode*> children; //letters 
    bool endofword; 

    TrieNode() {
    // //we don't need to do this as hashmap will already be nullptr intialised
    // for(int i = 0 + 'a'; i < 26 + 'a'; i++) { 
    //     children[i] = nullptr;
    // }

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
            if (cur->children.find(c) == cur->children.end()) { //not found
                cur->children[c] = new TrieNode(); //create new character
            }
            cur = cur->children[c];
        }   
         cur->endofword = true; //mark the last character as endofword
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
           if (cur->children.find(c) == cur->children.end()) {
                return false; //not found
            }
            cur = cur->children[c];
        }
        return cur->endofword; //check if its really the end of the word
    }
    
    bool startsWith(string prefix) {
         TrieNode* cur = root;
        for (char c : prefix) {
            if (cur->children.find(c) == cur->children.end()) {
                return false; //not found
            }
            cur = cur->children[c];
        }
        return true; //the difference here is after prefix is over, return true (we don't care if the word has finished or not)
    }
};
