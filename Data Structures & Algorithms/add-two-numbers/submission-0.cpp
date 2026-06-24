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
    ListNode* add(ListNode* l1, ListNode* l2, int carry) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;

    if(l1==nullptr && l2==nullptr && carry == 0) return nullptr; //carry shold also be 1 or we need to create new node 
    
    //when both lists are not null (one of them is null or both exist)
    int v1 = l1==nullptr? 0: l1->val; //0 because we need to perform addition with the non-null lists's value
    int v2 = l2==nullptr? 0: l2->val;

    int sum = v1 + v2 + carry;
    int newcarry = sum/10;//remember
    int cur_nodeVal = sum%10;

    ListNode* nextNode = add(l1 ? l1->next: nullptr, l2 ? l2->next: nullptr, newcarry);
    //first the last node will be created
    return new ListNode(cur_nodeVal, nextNode);
    
    }



    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       //iterative
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        int carry = 0;
        
        while(l1!=nullptr || l2!=nullptr || carry != 0){ //remember this condition
            int v1 = l1==nullptr? 0: l1->val; //0 because we need to perform addition with the non-null lists's value
            int v2 = l2==nullptr? 0: l2->val;

            int sum = v1 + v2 + carry;
            carry = sum/10;//remember
            int cur_nodeVal = sum%10;

            cur->next = new ListNode(cur_nodeVal);
            cur = cur->next; 

            l1 = l1!=nullptr  ? l1->next : nullptr;
            l2 = l2!=nullptr  ? l2->next : nullptr;

        }

        return dummy->next;
      
      //recursive
      //return add(l1, l2, 0);
    }
};
