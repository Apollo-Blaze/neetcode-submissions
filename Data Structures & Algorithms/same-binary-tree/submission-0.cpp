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
    bool same=true;
    void check(TreeNode* p, TreeNode* q){
        if(p && q){
            if(p->val!=q->val) same=false;
            check(p->left,q->left);
            check(p->right,q->right);
        }
        else if((p && !q) || (!p && q)) same=false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        check(p,q);
        return same;
    }
};
