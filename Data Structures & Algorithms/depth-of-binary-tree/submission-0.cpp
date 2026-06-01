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
    int maxCount(TreeNode* root,int count){
        if(root){ 
            count++;
            return(max(maxCount(root->left,count),maxCount(root->right,count)));
        }
        else return count;
    }
    int maxDepth(TreeNode* root) {
        return maxCount(root,0);
    }
};
