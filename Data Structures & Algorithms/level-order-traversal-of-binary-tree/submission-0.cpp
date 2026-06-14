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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(!root) return result;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            vector<int> level;
            int cur_size = q.size(); //current level
            
            //add all the nodes of the current level to the level set and
            //add the children to the queue (only the children of the current level nodes)

            for(int i = cur_size; i > 0; i--) {
                TreeNode* curr = q.front();
                q.pop();

                if(curr) { //if its not NULL
                level.push_back(curr->val);
                q.push(curr->left);
                q.push(curr->right);
               }
            }
            if(!level.empty())
               result.push_back(level);
            }
        return result;
    }
};
