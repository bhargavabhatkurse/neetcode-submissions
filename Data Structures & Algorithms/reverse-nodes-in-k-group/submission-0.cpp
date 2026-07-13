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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        ListNode* next;
        int t = k; 

        while(ptr != nullptr && t > 0) {
                ptr = ptr->next;
                t--;
        }

        if(t != 0) return head; //if less than k nodes, return as it is

        next = ptr;

        ListNode* prev = nullptr, *curr = head;
        
        while(curr != next) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        head->next = reverseKGroup(next,k);
    
        return prev;
    }
};
