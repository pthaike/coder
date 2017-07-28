


/**
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode* p = NULL;
        if(l1->val > l2->val)
        {
            p = l2; l2 = l2->next;
        }
        else
        {
             p = l1; l1 = l1 -> next;
        }
        ListNode* p1 = p;
        while(l1 && l2)
        {
            if(l1 -> val < l2->val)
            {
                p1->next = l1;
                l1 = l1->next;
            }
            else
            {
                p1->next = l2;
                l2 = l2->next;
            }
            p1 = p1->next;
        }
        if(l1 != NULL)
            p1->next = l1;
        if(l2 != NULL)
            p1->next = l2;
        return p;
    }
};
