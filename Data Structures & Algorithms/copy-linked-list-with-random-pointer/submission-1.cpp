/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    //2 pass solution
       Node* dummy = new Node(0);
       Node* ptr = dummy;

    unordered_map<Node*, Node*> mp;
    Node* head2 = head;
   
    while(head != nullptr) {
        Node* node = new Node(head->val);
        node->next = head->next;
        node->random = nullptr; //dont assign random here;

        mp[head] = node; //map this
        
        head = head->next;
        ptr->next = node;
        ptr = ptr->next;
    }
   
   //second pass: attach the randoms
   Node* it = dummy->next;
   head = head2; //reset the head;
   while(head != nullptr) {
       it->random = mp[head->random];
       it = it->next;
       head = head->next;
   }


    return dummy->next;
    }
};
