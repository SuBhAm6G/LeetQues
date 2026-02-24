class Solution {
public:
    int dfs(TreeNode* node, int current) {
        if (!node) return 0;

        // Build current binary number
        current = current * 2 + node->val;
        // If leaf node, return the number formed
        if (!node->left && !node->right)
            return current;

        return dfs(node->left, current) + dfs(node->right, current);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};