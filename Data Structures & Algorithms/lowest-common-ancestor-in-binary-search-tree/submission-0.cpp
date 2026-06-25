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
    TreeNode* lowestCommonAncestor_rec(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!(root || p || q)) return nullptr;

        if(max(p->val,q->val) < root->val) {
            return lowestCommonAncestor_rec(root->left,p,q);
        }
        else if(min(p->val,q->val) > root->val) {    //it is min here
            return lowestCommonAncestor_rec(root->right,p,q);
        }
        else return root;

    }

     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        while(curr) {
        if(max(p->val,q->val) < curr->val) {
            curr = curr->left;
        }
        else if(min(p->val,q->val) > curr->val) {    //it is min here
            curr = curr->right;
        }
        else return curr;
       }
        return nullptr;
        }
};
