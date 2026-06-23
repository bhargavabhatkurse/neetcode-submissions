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
     ListNode* mergeKLists(vector<ListNode*>& lists) {
       //USING array: O(nk) 
       
       //remember the cmp flips here
       auto cmp = [](ListNode* a, ListNode* b) {
         return a->val < b->val;
       };

      vector<ListNode*> min_array;

       for(int i = 0; i < lists.size();i++) {
        if(lists[i] != nullptr) min_array.push_back(lists[i]);
       } 
       
       ListNode* res = new ListNode(0);
       ListNode* curr = res;

       while(!min_array.empty()) {
          auto node = *min_element(min_array.begin(),min_array.end(),cmp);
          curr->next = new ListNode(node->val);
          curr=curr->next;
          erase(min_array, node); //delete the element to maintain size of array as k
          node = node->next;
         if(node) {
             min_array.push_back(node);
         }
       }
       return res->next;
        
    }


   ListNode* mergeKLists_heap(vector<ListNode*>& lists) {
       //USING HEAP: O(nlogk) 

       auto cmp = [](ListNode* a, ListNode* b) {
         return a->val > b->val;
       };

       priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp); // remember to pass cmp in the argument as well as constr expects it

       for(int i = 0; i < lists.size();i++) {
        if(lists[i] != nullptr) pq.push(lists[i]);
       } 
       
       ListNode* res = new ListNode(0);
       ListNode* curr = res;

       while(!pq.empty()) {
        auto node = pq.top(); //minimum
         curr->next = new ListNode(node->val);
         curr=curr->next;
        pq.pop();
        node = node->next;
         if(node) {
            pq.push(node);
         }
       }
       return res->next;
        
    }
};
