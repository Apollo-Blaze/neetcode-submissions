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
    bool exist=false;
    void check(TreeNode* p, TreeNode* q){
        if(p && q){
            if(p->val!=q->val) same=false;
            check(p->left,q->left);
            check(p->right,q->right);
        }
        else if((p && !q) || (!p && q)) same=false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        same=true;
        check(p,q);
        return same;
    }
    void rcheck(TreeNode* a, TreeNode* b){
        if(a==NULL && b==NULL) {}
        else if((a==NULL && b!=NULL) || (a!=NULL && b==NULL)) {}
        else if(a->val==b->val) {
            if(isSameTree(a,b)) exist=true;
            else{
                rcheck(a->left,b);
                rcheck(a->right,b);
            }
        }
        else {
            rcheck(a->left,b);
            rcheck(a->right,b);
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        rcheck(root,subRoot);
        return exist;
    }
};


