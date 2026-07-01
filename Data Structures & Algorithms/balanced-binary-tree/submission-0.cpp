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
    int height(TreeNode* root) {
        //takes o(n)
        if(!root) return 0;
        
        return 1 + max(height(root->left), height(root->right));
    }
    bool isBalanced_bruteforce(TreeNode* root) {
        //bruteforce n2 becuase n*n for each node we are finding its height
         
         //for each node - o(n)
         if(!root) return true;
         int leftH = height(root->left);
         int rightH = height(root->right);
         if(abs(leftH - rightH) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right); //every node should be balanced

    }
    pair<bool,int> dfs(TreeNode* root) {
         if(!root) return {true,0}; //we rarely have to use make_pair<>, use {} instead
         auto leftB = dfs(root->left);
         auto rightB = dfs(root->right);
         if((leftB.first == true && rightB.first == true) && (abs(leftB.second - rightB.second) <= 1)) return {true,1+max(leftB.second,rightB.second)};
    
        return {false,1+max(leftB.second,rightB.second)};
    }

     bool isBalanced(TreeNode* root) {
        auto p = dfs(root);
        return p.first;

    }
};
