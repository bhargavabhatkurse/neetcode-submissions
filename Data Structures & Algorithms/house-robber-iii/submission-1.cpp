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
    unordered_map<TreeNode*, int> dp;
    int rec(TreeNode* root) {
       int takenL = 0,takenR = 0;
       if(root == nullptr) return 0; 
       if(dp.count(root)) return dp[root];
       
       int nottaken = rec(root->left) + rec(root->right); //if not taken, you can rob both its children
       
       //taken (can't take the children but can take grandchildren)
       if(root->left) {        
       takenL = rec(root->left->left)+rec(root->left->right);
       }
       if(root->right) {
       takenR = rec(root->right->left)+rec(root->right->right);
       }

       int taken = root->val + takenR + takenL;
       
        return dp[root] = max(taken,nottaken);
        }


    int rob(TreeNode* root) {
        return rec(root);
    }
};