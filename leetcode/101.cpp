/**
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

*/

/*
#include <stdio.h>
#include <queue>
using namespace std;

  struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };



bool isSymmetric(TreeNode* root)
{
    if(root == NULL)
    {
        return true;
    }
    queue<TreeNode*> qleft;
    queue<TreeNode*> qright;
    qleft.push(root->left);
    qright.push(root->right);
    TreeNode * p1, *p2;
    while(!qleft.empty()&&!qright.empty())
    {
        p1 = qleft.front();
        p2 = qright.front();
        qleft.pop();
        qright.pop();

        if(p1==NULL && p2 == NULL)
        {
            continue;
        }
         else if( p1!=NULL && p2 != NULL && p1->val == p2->val)
        {
            qleft.push(p1->left);
            qleft.push(p1->right);
            qright.push(p2->right);
            qright.push(p2->left);
        }
        else
        {
            return false;
        }
    }
    return true;
}
*/
