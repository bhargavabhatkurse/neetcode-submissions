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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;

        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }
        else {
            //single child 
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            //both child exists
            TreeNode* cur = root->right;
            while (cur->left) {
                cur = cur->left;
            }
            cur->left = root->left; //inorder successor

            TreeNode* res = root->right; //promote the tree(this is different from replace with inroder successor textbook way)
            delete root;
            return res;
            }

            return root;
    }
};