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
    ListNode* reverseList_iter(ListNode* head) {
     //iteration
     ListNode* curr = head;
     ListNode* prev = NULL;
    //we are using 3 pointers here: curr, prev, and next
     while(curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
     }
        head = prev;

        return head;

    }

    ListNode* reverseList(ListNode* head) { 
        if(!head) return nullptr; //to handle the null input

        //ask recursion to reverse all ahead of you. Then you attach yourself to the partial reversed list returned to you
        
        ListNode* newhead = head; //is there because the last node should return itself as the new head.

        if(head->next) //goes till the last node (last node is returned as it is)
        {
            newhead = reverseList(head->next); //the reverselist recursion is always provide the new head
            head->next->next = head; //head->next will become the tail of the reversed list
            //therefore, attach yourself to the tail. 
        } 
        head->next = nullptr; //delete the old link

        return newhead;

    }
    /* 
    ```text
Example:

Original List:

1 -> 2 -> 3 -> nullptr

====================================================
Call Stack (Going Down)

Call 1:

reverseList(1)

head = 1
newHead = 1

head->next exists

So recurse:

newHead = reverseList(2)

----------------------------------------------------

Call 2:

reverseList(2)

head = 2
newHead = 2

head->next exists

So recurse:

newHead = reverseList(3)

----------------------------------------------------

Call 3:

reverseList(3)

head = 3
newHead = 3

head->next == nullptr

No recursive call.

Execute:

head->next = nullptr

(still nullptr)

Return newHead

Returns:

3

====================================================
Recursion starts returning (Going Up)

Return to Call 2

Current situation:

head = 2

newHead = 3

The recursive call has already reversed everything after 2.

Current list:

2 -> 3

Returned reversed part:

3

Now reverse the edge:

head->next->next = head

becomes

3->next = 2

Temporary structure:

2 <----> 3

Break the old forward link:

head->next = nullptr

Now:

3 -> 2 -> nullptr

Return:

newHead = 3

====================================================

Return to Call 1

Current situation:

head = 1

newHead = 3

Current pointers:

1 -> 2

Returned reversed part:

3 -> 2

Reverse the edge:

head->next->next = head

becomes

2->next = 1

Temporary structure:

3 -> 2 <----> 1

Break the old forward link:

head->next = nullptr

Now:

3 -> 2 -> 1 -> nullptr

Return:

newHead = 3

====================================================

Final Answer:

3 -> 2 -> 1 -> nullptr

====================================================
Values of newHead during execution:

Call on node 3:
newHead = 3
returns 3

↑

Call on node 2:
newHead becomes 3
returns 3

↑

Call on node 1:
newHead becomes 3
returns 3

====================================================
Key Idea

Going Down:
The recursion simply travels to the last node.

Coming Up:
Each node reverses exactly ONE pointer:

3->next = 2
2->next = 1

The last node (3) is returned unchanged and becomes the head of the reversed list.

Every recursive call returns the same pointer (3) after attaching itself to the end of the already reversed list.
```

    */

};
