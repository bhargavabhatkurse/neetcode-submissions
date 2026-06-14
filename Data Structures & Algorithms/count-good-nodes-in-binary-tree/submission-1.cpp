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
        return dfs(root,root->val); //current max_val is root val
    }

    int dfs(TreeNode* node, int max_val) {
        //max_val tracks the maximum value in the path
        if(!node) return 0;

        int good_nodes = node->val >= max_val ? 1 : 0; //check if the current node is good or not
        max_val = max(max_val, node->val);
        good_nodes += dfs(node->left,max_val);
        good_nodes += dfs(node->right,max_val);

        return good_nodes;
    }

};
