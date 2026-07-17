/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> m;
    Node* cloneGraph_(Node* node) {
        //dfs solution (v + E)
       if(!node) return nullptr;

       if(m.count(node)) return m[node]; //if original already cloned, return the cloned node

        Node* clone = new Node(node->val);
        m[node] = clone; //save the address of the cloned node of the original

        //remember how to traverse a graph
        for(auto nei: node->neighbors) {
            clone->neighbors.push_back(cloneGraph(nei)); //clone all its neighbours
        }

        return clone;
    
    }

     Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*,Node*> m; //mapping old to new
        queue<Node*> q;
        
        m[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(auto nei: cur->neighbors) {
                if(!m.count(nei)) { //if not found
                    m[nei] = new Node(nei->val);
                    q.push(nei); //we have to create its neighbours too in the future
                }
                m[cur]->neighbors.push_back(m[nei]);
            }
        }   
        return m[node];

     }
};
