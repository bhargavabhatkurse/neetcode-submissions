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
int maximum = INT_MIN;

    int rec(TreeNode* root) {
        if(root == nullptr) return 0;

        int maxR = rec(root->right);
        int maxL = rec(root->left);

        if(root->val + maxR < root->val) maxR = 0;
        if(root->val + maxL < root->val) maxL = 0;

        int curr_max = maxR + maxL + root->val;
        maximum = max(maximum,curr_max);
        return max(maxR,maxL) + root->val;
;
    }

     int maxPathSum(TreeNode* root) {
        int m = rec(root);
        return maximum;
     }
};
