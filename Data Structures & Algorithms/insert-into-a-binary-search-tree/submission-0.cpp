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
    TreeNode* insertIntoBST_iteration(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }

        TreeNode* node = new TreeNode(val);

        TreeNode* ptr = root;

        while(true) {
            if(ptr->val > node->val) {
                if(ptr->left == nullptr) {
                    ptr->left = node;
                    return root;
                }
            ptr = ptr->left;
            }
            else {
            if(ptr->right == nullptr) {
                ptr->right = node;
             return root;
             }
            ptr = ptr->right;
            }
        }
        return root;
    }

     TreeNode* insertIntoBST(TreeNode* root, int val) {
          if (!root) {
            return new TreeNode(val);
        }
        TreeNode* ptr = root;
        if(ptr->val < val) {
            ptr->right = insertIntoBST(ptr->right,val);
        }
        else {
              ptr->left = insertIntoBST(ptr->left,val);
        }
        return root;
     }
};