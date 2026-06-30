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
    void reorderList_bruteforce(ListNode* head) {
        //bruteforce -o(n) but also o(n) space
        vector<ListNode*> arr; 

        //store all nodes
        ListNode* curr = head;
        while(curr) {
            arr.push_back(curr);
            curr = curr->next;
        }
        

        int left = 0, right = arr.size()-1;

        while(left < right) {
           arr[left]->next = arr[right];
           left++;
        
            if(left==right) break;
           
           arr[right]->next = arr[left]; //right should point to the next left
           right--;
        }

        arr[left]->next = nullptr; //important: end the list manually
    }

     void reorderList(ListNode* head) {
    //reverse and merge
    //reverse the second half and then merge both ll alternatively 

    ListNode* slow = head, *fast = head->next; //we need this to find the middle of the list

    //technique to find the middle element (first middle) - if you want to find second middle use fast = head, not fast=head->next
    // 1 2 3 4, slow points to 2 > first middle
    //            slow points to 3 > second middle


    while(fast && fast->next) //till fast reaches last node or the beyond
    {
        slow = slow->next;
        fast = fast->next->next;
    }


    //we need to reverse the second half
    ListNode* second = slow->next; //start of the second list
    slow->next = nullptr; //this will be last node of the second list
    ListNode* prev = nullptr;
    while(second != nullptr) {
        ListNode* next = second->next;
        second->next = prev;
        prev = second;
        second = next;
    }

    //now merge alternatively
     ListNode* first = head;
     second = prev;

     while(second != nullptr) {
    ListNode* p1 = first->next;
     ListNode* p2 = second->next;
     
     first->next = second;
     second->next = p1;
     first = p1;
     second = p2;
     }
     }
};
