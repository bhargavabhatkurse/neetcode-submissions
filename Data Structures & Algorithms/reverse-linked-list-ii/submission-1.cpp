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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ptr = head;
        ListNode *leftN, *rightN,
            *leftH = nullptr, *rightH;  // H variables keep track of leftprevious and rightnext part

        while (ptr != nullptr && --left) {
            leftH = ptr;
            ptr = ptr->next;
        }

        leftN = ptr;

        ptr = head;
        while (ptr != nullptr && --right) {
            ptr = ptr->next;
        }
        rightN = ptr;
        rightH = ptr ? ptr->next : nullptr;

        // reverse between left and right
        ListNode* prev = nullptr;
        ListNode* next;
        ptr = leftN;
        while (ptr != rightH) {
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }

        if (leftH)
            leftH->next = rightN;
        else
            head = rightN;
        
        leftN->next = rightH;

        return head;
    }
};