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

    //This soln is not recommended - Just see the remember the syntax

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //bruteforce - collect all elements, sort and then rebuild the list
       
       // o(n*k) solution - collect min from each list and add it to result
        vector<int> sorted; //collects the entire sorted array 
        vector<pair<int,int>> min_array; //it will hold k elements and their list index
        int n = lists.size();
        while(true) {
        vector<bool> valid_index(n,1);
        int count = n;
        for(int i = 0; i < lists.size(); i++) { //this loops checks which indices are valid
            if(lists[i] == nullptr) {
            valid_index[i] = 0;
            count--;
            }
        }
        if(count == 0) break; //if none are valid
        
        for(int i = 0; i < lists.size(); i++) { //k - list array
            if(!valid_index[i]) continue; 
            min_array.push_back({lists[i]->val,i});
        }

        pair<int,int> min_el = *min_element(min_array.begin(),min_array.end());
        sorted.push_back(min_el.first);
        erase(min_array,min_el); //to maintain the list of k elements
        lists[min_el.second] = lists[min_el.second]->next;
        }

        //build the list
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        for(int node: sorted) {
            curr->next = new ListNode(node);
            curr = curr->next;
        }

        return res->next;
  
    }
};
