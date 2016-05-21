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
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> res;
    vector<int> elem;
    q.push(root);
    TreeNode* p;
    TreeNode* flag;
    TreeNode* tmp;
    flag = root;
    tmp = root;
    while(!q.empty()){
        p = q.pop();
        elem.push_back(p.val);
        if(p == flag){
            res.push_back(elem);
            vector<int> elem;
            flag = tmp;
        }
        else{
            elem.push_back(p.val);
        }
        if(NULL != p.left){
            q.push(p.left);
            tmp = p.left;
        }
        if(NULL != p.right){
            q.push(p.right);
            tmp = p.right;
        }
        if(p == flag){
            flag = tmp;
        }
    }
}

int main(void)
{
    return 0;
}
