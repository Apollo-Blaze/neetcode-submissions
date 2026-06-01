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
    bool avl=true;
    int check(TreeNode* root, int count){
        int l,r;
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        else{
            l=check(root->left,count);
            r=check(root->right,count);
            int diff=abs(l-r);
            if(diff!=0 && diff!=1) avl=false;
            return max(l,r)+1;
        }
    }
    bool isBalanced(TreeNode* root) {
        check(root,0);
        return avl;
    }
};
