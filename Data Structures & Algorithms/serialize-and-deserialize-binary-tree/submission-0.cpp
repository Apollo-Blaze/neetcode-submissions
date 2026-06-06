/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    void dfs_serialize(TreeNode* node, string& res){
            if(!node){
                res += "#,";
                return;
            }
            res += to_string(node->val) + ",";
            dfs_serialize(node->left, res);
            dfs_serialize(node->right, res);
        }
    string serialize(TreeNode* root) {
        string res = "";
        dfs_serialize(root, res);
        return res;
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        string token = "";
        for(char c : data){
            if(c == ','){
                if(!token.empty()) q.push(token);
                token = "";
            } else {
                token += c;
            }
        }
        return dfs_deserialize(q);
    }
    
    TreeNode* dfs_deserialize(queue<string>& q){
        if(q.empty()) return nullptr;
        string val = q.front();
        q.pop();
        if(val == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = dfs_deserialize(q);
        node->right = dfs_deserialize(q);
        return node;
    }
};
