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
    ListNode* merge(ListNode* x, ListNode* y) {
      ListNode* res = new ListNode(0); //dummy node
      ListNode* curr = res;

      while(x != nullptr && y != nullptr) {
        if(x->val <= y-> val) {
          // curr->next = new ListNode(x->val); This will make the space complexity o(n)
          curr->next = x;
          curr = curr->next;
          x = x->next;
        }
        else {
          curr->next = y;
          curr = curr->next;
          y = y->next;
        }
      }
      if(y == nullptr) //no while loops will come here because we are directly assigning
          curr->next = x;
        else
          curr->next = y;
      
        return res->next;
     }


    ListNode* divide(vector<ListNode*>& lists, int l, int r) {
      //o(nlogk)
      if( l  > r) return nullptr; //when the list is empty (list, 0, -1) - edge case

      if(l == r) return lists[l]; //only one list is remaining (it is already sorted)

      int mid = l + (r-l)/2;

      ListNode* left = divide(lists,l, mid);
      ListNode* right = divide(lists, mid+1, r);

      return merge(left,right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
     // o(nk) -- Divide and Conquer
    return divide(lists,0, lists.size()-1);
    }
};
