class Solution {
public:
    int k;
    int ans;

    void inorder(TreeNode* root) {
        if (!root || k == 0) return;

        inorder(root->left);

        k--;
        if (k == 0) {
            ans = root->val;
            return;
        }

        inorder(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        inorder(root);
        return ans;
    }
};