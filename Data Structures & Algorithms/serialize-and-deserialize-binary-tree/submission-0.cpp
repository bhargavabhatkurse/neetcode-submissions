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

private: 
        void dfsSerialize(TreeNode* node, vector<string>& res) {
        //preorder
        if (!node) {
            res.push_back("N");
            return;
        }
        res.push_back(to_string(node->val));
        dfsSerialize(node->left, res);
        dfsSerialize(node->right, res);
    }

    TreeNode* dfsDeserialize(vector<string>& vals, int& i) {
        //when nulls are included, only preorder is enough to generate the tree
        if (vals[i] == "N") {
            i++;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = dfsDeserialize(vals, i);
        node->right = dfsDeserialize(vals, i);
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerialize(root, res);
        return join(res, ","); //join and make one string
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, ',');
        int i = 0;
        return dfsDeserialize(vals, i);
    }

    string join(const vector<string>& v, const string& delim) {
    string ans; //join the string
    for (int i = 0; i < v.size(); i++) {
        if (i > 0)
            ans += delim;
        ans += v[i];
    }
    return ans;
    }

    vector<string> split(const string &s, const char& delim) {
    vector<string> ans; 
    
    int left = 0;
    for (int right = 0; right < s.size(); right++) {
        if(s[right] == delim) {
        ans.push_back(s.substr(left,right-left)); //add the node
        left = right+1;
        }
    }
      ans.push_back(s.substr(left)); //last node remaining is added
    return ans;
    }
};
