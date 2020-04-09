// Date:        2020.4.8
// Topic:       Linklist
// Todo:        Totally understand the dfs method

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* p1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* p2 = lowestCommonAncestor(root->right, p, q);

        if (p1 && p2) {
            return root;
        } else {
            return p1 ? p1 : p2;
        }
    }
};
