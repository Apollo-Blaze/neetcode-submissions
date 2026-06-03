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
    int count=0;
    void cal(TreeNode* root,int m){
        if(root->val>=m) {
            count++;
            if(root->left) cal(root->left,root->val);
            if(root->right) cal(root->right,root->val);
        }
        else{
            if(root->left) cal(root->left,m);
            if(root->right) cal(root->right,m);
        }

    }
    int goodNodes(TreeNode* root) {
        if(root) cal(root,root->val);
        return count;
    }
};
