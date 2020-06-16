Date:       2020.04.12
Topic:      Binary Tree + DFS
Todo:       Using BFS
class Solution {
    int maxDiam = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return maxDiam;
    }

    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        maxDiam = max(maxDiam, left + right);
        return max(left,right) + 1;
    }
};
