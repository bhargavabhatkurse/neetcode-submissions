/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        // //unordered_set<int> duplicate; //we need to detect same node, not value
        // unordered_set<ListNode*> duplicate;
        // ListNode* curr = head;
        // while(curr) {
        //     if(duplicate.count(curr)) return true;

        //     duplicate.insert(curr);
        //     curr = curr->next;
        // }
        // return false; //no cycle

        //fast and slow pointers
        
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next; //moves 2 steps
        slow = slow->next;

        if(fast == slow) return true; //eventually the fast pointer will catchup if there is a cycle
        }
        return false;
    }
};
