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
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }

private:
    int dfs(TreeNode* node, int curMin, int curMax) {
        if (!node) {
            return curMax - curMin;
        }

        curMin = min(curMin, node->val);
        curMax = max(curMax, node->val);

        int leftDiff = dfs(node->left, curMin, curMax);
        int rightDiff = dfs(node->right, curMin, curMax);

        return max(leftDiff, rightDiff);
        
    }
};


    