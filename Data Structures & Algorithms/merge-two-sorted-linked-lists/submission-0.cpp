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
    ListNode* mergeTwoLists_iterative(ListNode* list1, ListNode* list2) {
       
       //iterative 

       //The merge procedure for LL is 0(1) but for arrays it is 0(n);
       ListNode* dummy = new ListNode(0);
       ListNode* curr = dummy;

       while(list1 != nullptr && list2 != nullptr) {
            if(list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
       }

       if(list1) {
        curr->next = list1;
       }

       else {
        curr->next = list2;
       }

       return dummy->next;
  
    }


     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //question to be asked: who should be the smallest element? 

        if(list1 == nullptr) {
            return list2; //because list1 is empty
        }

        if(list2 == nullptr) {
            return list1;
        }

        if(list1->val <= list2->val) //list1 val is smaller
        {
           //whatever is the result of the future merged list, I will attach myself and return;
           //list1 is the smaller node here
           list1->next = mergeTwoLists(list1->next, list2);
           return list1;
        }
        else {
            list2->next = mergeTwoLists(list1,list2->next);
           return list2;
        }
        
     }

// Example:

// list1: 1 -> 3 -> 5
// list2: 2 -> 4 -> 6

// Call:
// merge(1->3->5, 2->4->6)

// ----------------------------------------------------
// Call 1:

// Compare:
// 1 vs 2

// 1 is smaller.

// So 1 must be the head of the merged list.

// We don't yet know what comes after 1, so we recursively merge:

// 1->next = merge(3->5, 2->4->6)

// Current state:

// 1 -> ?

// ----------------------------------------------------
// Call 2:

// Compare:
// 3 vs 2

// 2 is smaller.

// So 2 becomes the next node.

// 2->next = merge(3->5, 4->6)

// Current state:

// 2 -> ?

// ----------------------------------------------------
// Call 3:

// Compare:
// 3 vs 4

// 3 is smaller.

// 3->next = merge(5, 4->6)

// Current state:

// 3 -> ?

// ----------------------------------------------------
// Call 4:

// Compare:
// 5 vs 4

// 4 is smaller.

// 4->next = merge(5, 6)

// Current state:

// 4 -> ?

// ----------------------------------------------------
// Call 5:

// Compare:
// 5 vs 6

// 5 is smaller.

// 5->next = merge(nullptr, 6)

// Current state:

// 5 -> ?

// ----------------------------------------------------
// Call 6 (Base Case):

// list1 == nullptr

// Return list2.

// Returned list:

// 6

// ----------------------------------------------------
// Now recursion starts returning.

// Return to Call 5:

// 5->next = 6

// Result:

// 5 -> 6

// Return head = 5

// ----------------------------------------------------
// Return to Call 4:

// 4->next = (5 -> 6)

// Result:

// 4 -> 5 -> 6

// Return head = 4

// ----------------------------------------------------
// Return to Call 3:

// 3->next = (4 -> 5 -> 6)

// Result:

// 3 -> 4 -> 5 -> 6

// Return head = 3

// ----------------------------------------------------
// Return to Call 2:

// 2->next = (3 -> 4 -> 5 -> 6)

// Result:

// 2 -> 3 -> 4 -> 5 -> 6

// Return head = 2

// ----------------------------------------------------
// Return to Call 1:

// 1->next = (2 -> 3 -> 4 -> 5 -> 6)

// Result:

// 1 -> 2 -> 3 -> 4 -> 5 -> 6

// Return head = 1

// ----------------------------------------------------
// Final merged list:

// 1 -> 2 -> 3 -> 4 -> 5 -> 6

// ====================================================

// The key lines are:

// if (list1->val <= list2->val) {
//     list1->next = mergeTwoLists(list1->next, list2);
//     return list1;
// }

// Meaning:

// 1. Choose the smaller node as the head.
// 2. Recursively merge the remaining lists.
// 3. Attach the merged result to head->next.
// 4. Return the chosen head.

// Each recursive call decides exactly ONE node (the smallest of the two current heads), and lets recursion merge the rest.


};
