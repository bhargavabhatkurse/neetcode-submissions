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
        //return dfs(root,root->val); //current max_val is root val
        return bfs(root);
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

     int bfs(TreeNode* root) {
        int count = 0;
        queue<pair<TreeNode*,int>> q;
        if(root == nullptr) return 0;
        q.push({root, root->val});

        while(!q.empty()) {
        auto [node,max_val] = q.front();
        q.pop();
        if(node == nullptr) continue; //we need to do this because we are pushing nullptr as children 
        if(node->val >= max_val) count++;
        max_val = max(max_val, node->val);
        q.push({node->left,max_val});
        q.push({node->right,max_val});
        }

        return count;
     }

};
