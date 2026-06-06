class PrefixTree {
public:
    unordered_set<string> trie;
    PrefixTree() {
        
    }
    
    void insert(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.find(word)==trie.end()?false:true;
    }
    
    bool startsWith(string prefix) {
        int l=prefix.size();
        for(auto x:trie){
            if(prefix==x.substr(0,l)) return true;
        }
        return false;
    }
};
