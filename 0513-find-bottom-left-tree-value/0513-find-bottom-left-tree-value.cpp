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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int leftmost;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            leftmost = node->val;

            if(node->right != NULL){
                q.push(node->right);
            }
            if(node->left != NULL){
                q.push(node->left);
            }
        }
    return leftmost;

    }
};