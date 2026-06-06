class PrefixTree {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord = false;
    };
    
    TrieNode* root;
    
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(!curr->children.count(c))
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(!curr->children.count(c)) return false;
            curr = curr->children[c];
        }
        return curr->isEndOfWord;  // ✅ must be end of actual word
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix){
            if(!curr->children.count(c)) return false;
            curr = curr->children[c];
        }
        return true;  // ✅ found the prefix path
    }
};