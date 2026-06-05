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
    int goodNodes(TreeNode* root) {
        int count = 0;

        dfs(root, root->val, count);

        return count;        
    }

    void dfs(TreeNode* root, int mx, int &count){
        if(root == nullptr) return;

        if(root -> val >= mx){
            count++;
            mx = root->val;
        }

        dfs(root->left, mx, count);

        dfs(root->right, mx, count);
    }
};