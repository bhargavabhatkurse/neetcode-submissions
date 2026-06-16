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
    vector<vector<int>> res; 
    vector<vector<int>> levelOrder(TreeNode* root) {
    //DFS soln
    DFS(root,0); //for dfs, keep the res outside and run void dfs
   return res;
    }
    void DFS(TreeNode* root, int depth) {
        if(!root) return;
        
        //important to create the empty list 
        //when visiting the level for the first time
        if(res.size() == depth) res.push_back(vector<int>());
        res[depth].push_back(root->val);
        DFS(root->left, depth+1);
        DFS(root->right, depth+1);
    }

    vector<vector<int>> BFS(TreeNode* root) {
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
