/*
102. Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/



#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;


vector<vector<int>> levelOrder(TreeNode* root)
{
    queue<TreeNode*> q;
    TreeNode* flag, *tmpflag, *p;
    q.push(root);
    flag = root;
    vector<vector<int>> res;
    if(root==NULL){
        return res;
    }
    vector<int> v1;
    while(!q.empty()){
        p = q.front();
        q.pop();
        v1.push_back(p->val);
        if(p->left!=NULL){
            q.push(p->left);
            tmpflag = p->left;
        }
        if(p->right!=NULL){
            q.push(p->right);
            tmpflag = p->right;
        }
        if(p == flag){
            vector<int> v2 = v1;
            res.push_back(v2);
            v1.clear();
            flag = tmpflag;
        }
    }
    return res;
}

