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
int maximum = 0;
int rec(TreeNode* root) {
    //dfs - o(n) , space -(logh) max depth it can take
        if(root == nullptr) return 0;
        int maxL = rec(root->left);
        int maxR = rec(root->right);
        maximum = max(maximum,maxL + maxR);
        return 1+max(maxL, maxR); //return height, but update diamter in the maximum
}
    int diameterOfBinaryTree(TreeNode* root) {
        rec(root);
        return maximum;
    }
};
