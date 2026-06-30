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
    void reorderList(ListNode* head) {
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
};
