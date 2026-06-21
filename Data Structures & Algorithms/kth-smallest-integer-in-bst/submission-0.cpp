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
    int kthSmallest(TreeNode* root, int k) {
        pair<int,int> p;
        p.first = k;
        dfs(root,p);
        return p.second;
    }

    void dfs(TreeNode* root, pair<int,int> &p)
    {   
        //inorder traversal O(h+k), O(h) for the recursion stack (remember this is the complexity for inorder traversals)
        if(!root) return;

        dfs(root->left,p);
        
        p.first--;
        if(p.first == 0){
            p.second = root->val;
            return;
        }
        
        dfs(root->right,p);


        //other solution is to make an array of the inorder traversal and
        //then find a[k-1]; o(n) but also 0(n space)

    }

};
