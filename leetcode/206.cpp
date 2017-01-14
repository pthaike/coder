/**
Reverse a singly linked list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        if(p == NULL)
            return NULL;
        while(p->next!=NULL)
            p = p->next;
        reverseListHelper(head);
        return p;
    }
    ListNode* reverseListHelper(ListNode* head)
    {
        ListNode* p;
        if(head != NULL)
        {
            p = reverseListHelper(head->next);
            if(p != NULL)
                p->next = head;
            head->next = NULL;
        }
        return head;
    }
};
