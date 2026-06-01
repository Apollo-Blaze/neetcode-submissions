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
    int d=0;
    int maxCount(TreeNode* root,int count){
        if(!root) return 0;
        if(!root->left && !root->right ) return 1;
        else{
            int l=maxCount(root->left,count);
            int r=maxCount(root->right,count);
            d=max(d,l+r);
            return max(l,r)+1;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxCount(root,0);
        return d;
    }
};
