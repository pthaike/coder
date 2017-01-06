/**
103. Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

*/


class Solution {
public:

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        stack<TreeNode*> s, s1;
        TreeNode* p;
        s.push(root);
        bool de = true;
        vector<int> v;
        while(!s.empty()){
            p = s.top();
            s.pop();
            v.push_back(p->val);
            if(de)
            {
                if(p->left!=NULL)
                    s1.push(p->left);
                if(p->right!=NULL)
                    s1.push(p->right);
            }
            else
            {
                if(p->right!=NULL)
                    s1.push(p->right);
                if(p->left!=NULL)
                    s1.push(p->left);
            }
            if(s.empty())
            {
                vector<int> v1 = v;
                res.push_back(v1);
                v.clear();
                s = s1;
                while(!s1.empty())
                    s1.pop();
                de = !de;
            }
        }
        return res;
    }
};

