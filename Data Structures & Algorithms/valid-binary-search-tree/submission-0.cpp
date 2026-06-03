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

class Solution {
public:
    vector<int> tr;
    void inorder(TreeNode* root){
        if(root)
        {
            inorder(root->left);
            tr.push_back(root->val);
            inorder(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        if(tr.size()==1) return true;
        for(int i=1;i<tr.size();i++){
            if(tr[i]<=tr[i-1]) return false;
        }
        return true;
    }
};
