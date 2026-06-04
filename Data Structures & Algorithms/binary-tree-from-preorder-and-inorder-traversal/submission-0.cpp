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
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> mp;
    for(int i=0; i<inorder.size(); i++)
        mp[inorder[i]] = i; 
    
    return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, mp);
}

TreeNode* build(vector<int>& pre, vector<int>& in, 
                int preStart, int preEnd, 
                int inStart, int inEnd,
                unordered_map<int,int>& mp){
    if(preStart > preEnd) return nullptr;
    
    int rootVal = pre[preStart];
    int rootIdx = mp[rootVal]; 
    
    int leftSize = rootIdx - inStart;  
    
    TreeNode* root = new TreeNode(rootVal);
    root->left = build(pre, in, preStart+1, preStart+leftSize, 
                       inStart, rootIdx-1, mp);
    root->right = build(pre, in, preStart+leftSize+1, preEnd, 
                        rootIdx+1, inEnd, mp);
    return root;
}
};
