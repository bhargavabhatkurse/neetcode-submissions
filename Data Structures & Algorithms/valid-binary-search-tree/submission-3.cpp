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
    bool rec(TreeNode* root,int low, int high) {
        if(!root) return true;

        if(root->val <= low || root->val >= high) return false;

        return rec(root->left,low,root->val) && rec(root->right,root->val, high);
    }
    bool isValidBST(TreeNode* root) {
        return rec(root,INT_MIN, INT_MAX);
    }
};
