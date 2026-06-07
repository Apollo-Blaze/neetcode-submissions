class Solution {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        string word = "";
    };
    
    void buildTrie(vector<string>& words, TrieNode* root){
        for(string& w : words){
            TrieNode* curr = root;
            for(char c : w){
                if(!curr->children.count(c))
                    curr->children[c] = new TrieNode();
                curr = curr->children[c];
            }
            curr->word = w;
        }
    }
    
    void dfs(int i, int j, TrieNode* node, 
             vector<vector<char>>& board, 
             vector<string>& result){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size())
            return;
        
        char c = board[i][j];
        if(c == '#' || !node->children.count(c))  
            return;
        
        TrieNode* child = node->children[c];
        if(child->word != ""){
            result.push_back(child->word);
            child->word = ""; 
        }
        
        board[i][j] = '#';  
        dfs(i+1, j, child, board, result);
        dfs(i-1, j, child, board, result);
        dfs(i, j+1, child, board, result);
        dfs(i, j-1, child, board, result);
        board[i][j] = c;   
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        buildTrie(words, root);
        vector<string> result;
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                dfs(i, j, root, board, result);
            }
        }
        return result;
    }
};