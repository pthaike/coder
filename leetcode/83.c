/**
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode * p, *pre;
        for(p=head->next, pre = head; p!=NULL; p = p->next)
        {
            if(p->val == pre->val)
            {
                pre->next = p->next;
                delete p;
                p = pre;
            }
            else
                pre = p;
        }
        return head;
    }
};
