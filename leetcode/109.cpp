

/**

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while(p)
        {
            len ++;
            p = p->next;
        }
        return sortedListToBSTHelp(head, len);
    }

    TreeNode* sortedListToBSTHelp(ListNode* head, int len) {
        if(len <= 0)
            return NULL;
        else if(len == 1)
            return new TreeNode(head->val);
        int mid = (len + 1) / 2;
        ListNode* p = head;
        for(int i = 1; i < mid; i++)
            p = p->next;
        TreeNode* left = NULL;
        if(mid-1 > 0)
            left = sortedListToBSTHelp(head, mid-1);
        TreeNode* right = NULL;
        if(p->next != NULL)
            right = sortedListToBSTHelp(p->next, len-mid);
        TreeNode* node = new TreeNode(p->val);
        node->left = left;
        node->right = right;
        return node;
    }
};
