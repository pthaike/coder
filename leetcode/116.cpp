/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        queue<TreeLinkNode *> q1;
        TreeLinkNode * p;
        q1.push(root);
        while(!q1.empty())
        {
            queue<TreeLinkNode *> q2;
            while(!q1.empty())
            {
                p = q1.front();
                q1.pop();
                if(q1.empty())
                    p->next = NULL;
                else
                    p->next = q1.front();
                if(p->left != NULL)
                    q2.push(p->left);
                if(p->right != NULL)
                    q2.push(p->right);
            }
            q1 = q2;
        }
    }
};
