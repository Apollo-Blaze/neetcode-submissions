class WordDictionary {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord = false;
    };
    
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(!curr->children.count(c))
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
    
    bool dfs(string& word, int idx, TrieNode* node){
        if(idx == word.size())
            return node->isEndOfWord;
        
        char c = word[idx];
        if(c == '.'){
            for(auto& [ch, child] : node->children){
                if(dfs(word, idx+1, child)) return true;
            }
            return false;
        } else {
            if(!node->children.count(c)) return false;
            return dfs(word, idx+1, node->children[c]);
        }
    }
};
