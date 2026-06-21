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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if(!root) return res;

        queue<TreeNode*> q; //* is important as its a queue of addresses
        q.push(root);

        while(!q.empty()) {
            int curr = q.size(); 
            vector<int> levelset;

            for(int i = 0; i < curr; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node) { //if that node exists
                    levelset.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(!levelset.empty()) { //to be safe its not empty, otherwise .back() wont work
                res.push_back(levelset.back());
            }
        }            
        return res;
    }
};
