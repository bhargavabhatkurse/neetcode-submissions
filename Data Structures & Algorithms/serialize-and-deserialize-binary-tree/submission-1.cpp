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

class Codec {
public: //check both submissions: BFS and DFS

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //bfs on trees is level order
        if (!root) return "N";
        string res;
        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            if (!node) {
                res += "N,";
            } 
            else {
                res += to_string(node->val) + ",";
                queue.push(node->left);
                queue.push(node->right);
            }
        }
        return res;
    }
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data); //treats the data like a stream
        
        string val;
        getline(ss, val, ','); //reads the root 

        if (val == "N") return nullptr;

        //create node
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> queue;
        queue.push(root);

        while (getline(ss, val, ',')) { //till new characters some from the stream
            TreeNode* node = queue.front();
            queue.pop();

            if (val != "N") {
                node->left = new TreeNode(stoi(val));
                queue.push(node->left); //need to build its children
            }
            getline(ss, val, ',');

            if (val != "N") {
                node->right = new TreeNode(stoi(val));
                queue.push(node->right);
            }
        }
        return root;
    }
};
