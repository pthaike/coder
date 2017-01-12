/**
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 ¡ú a2
                   ¨K
                     c1 ¡ú c2 ¡ú c3
                   ¨J
B:     b1 ¡ú b2 ¡ú b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0;
        int b = 0;
        ListNode * pa, *pb;
        for(pa = headA; pa != NULL; pa = pa->next)
            a++;
        for(pb = headB; pb != NULL; pb = pb->next)
            b++;
        pa = headA;
        pb = headB;
        if(a>b)
        {
            for(int i = 0; i < a-b; i++)
                pa = pa->next;
        }
        else if(a < b)
        {
            for(int i = 0; i < b - a; i++)
                pb = pb->next;
        }
        while(pa!=NULL&&pb!=NULL)
        {
            if(pa == pb)
                return pa;
            pa = pa->next;
            pb = pb->next;
        }
        return NULL;
    }
};
