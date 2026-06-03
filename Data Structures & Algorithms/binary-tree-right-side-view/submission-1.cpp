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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> bst;
        while(q.size()){
            vector<int> lvl;
            int n=q.size();
            while(n){
                TreeNode* temp=q.front();
                q.pop();
                n--;
                lvl.push_back(temp->val);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            bst.push_back(lvl);
        }
        vector<int> res;
        for(auto x:bst){
            res.push_back(x.back());
        }
        return res;
    }
};
