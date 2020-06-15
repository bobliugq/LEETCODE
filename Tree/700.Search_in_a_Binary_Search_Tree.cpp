// Recursion Method

TreeNode* searchBST(TreeNode* root, int val) {
    if (!root) return NULL;
    if (root->val < val) return searchBST(root->right, val);
    if (root->val > val) return searchBST(root->left, val);
    return root;
}

// Iteration Method

TreeNode* searchBST(TreeNode* root, int val) {
    while (!root && root->val != val) {
        root = root->val < val ? root->right : root->left;
    }
    return root;
}
