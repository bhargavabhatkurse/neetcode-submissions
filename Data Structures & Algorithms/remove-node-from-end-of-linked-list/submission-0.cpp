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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* ptr = head;
        while(ptr != NULL) {
            count++;
            ptr = ptr->next;
        }
        //remember: this is the index
        int del_index  = count - n; //from the start of the list
        
        if(del_index == 0) return head->next;
        
        ptr = head; //start from the first node (index = 0)
        int pos = 0;
        
        while(ptr) {
            if(pos == del_index - 1) { //next node is to be deleted
                ptr->next = ptr->next->next;
            }

            ptr = ptr->next;
            pos++;
        }
        return head;
    }
};
