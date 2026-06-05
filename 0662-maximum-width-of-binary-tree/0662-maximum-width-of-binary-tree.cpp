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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});
        unsigned long long maxLen = 0;
       
        while(!q.empty()){
            int n = q.size();

            unsigned long long min_idx = q.front().second; 
            unsigned long long l = 0, r = 0;

            for(int i=0; i<n; i++){
                auto p = q.front();
                q.pop();

                unsigned long long curr_idx = p.second - min_idx;

                if(i == 0){
                    l = p.second;
                }

                if(i == n-1){
                    r = p.second;
                }

                if(p.first -> left != nullptr){
                    q.push({p.first -> left, 2*curr_idx+1});
                }

                if(p.first -> right != nullptr){
                    q.push({p.first -> right, 2*curr_idx+2});
                }
            }

            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
    }
};