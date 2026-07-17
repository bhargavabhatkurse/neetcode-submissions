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
    int curPre = 0; //helps to decide the root
    unordered_map<int,int> m;

    TreeNode* build(vector<int>& preorder, int l, int r) {
            
            if(l>r) return nullptr;
            int val = preorder[curPre++]; //val of the root at this stage
            TreeNode* root = new TreeNode(val);
            int mid = m[val]; 
            root->left = build(preorder,l,mid-1);
            root->right = build(preorder,mid+1,r);
            
            //curPre++; can't do it here because otherwise the recursion calls will use the same curPre which is wrong
            return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size()-1);

    }
};
