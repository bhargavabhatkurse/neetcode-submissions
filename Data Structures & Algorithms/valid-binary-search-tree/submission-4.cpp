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
        //dfs
        if(!root) return true;

        if(root->val <= low || root->val >= high) return false; //remember it is equal to(=) also

        return rec(root->left,low,root->val) && rec(root->right,root->val, high); //remember to pass the children
    }
    bool isValidBST(TreeNode* root) {
        //return rec(root,INT_MIN, INT_MAX);

        if(!root) {
            return true;
        }

        queue<tuple<TreeNode*,int,int>> q;
        q.push({root,INT_MIN,INT_MAX});

        while(!q.empty()) {
            auto [node,l, r] = q.front();
            q.pop();
            
            if(node == nullptr) continue;

            if(l >= node->val || r <= node->val) return false;
            
            q.push({node->left,l,node->val}); 
            q.push({node->right,node->val,r});
        }
        return true;

    }
};
