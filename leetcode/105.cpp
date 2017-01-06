/**
Given preorder and inorder traversal of a tree, construct the binary tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size());
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, int preleft, int preright, vector<int>& inorder, int inleft, int inright)
    {
        if(preleft>preright)
            return NULL;
        int a = preorder[preleft];
        int i;
        for(i = 0; i + inleft < inorder.size(); i++)
        {
            if(inorder[i + inleft]==a)
                break;
        }
        TreeNode * node = &(new TreeNode(a));
        node->left = buildTreeHelper(preorder, preleft+1, preleft+i, inorder, inleft, inleft+i-1);
        node->right = buildTreeHelper(preorder, preleft+i+1, preright, inorder, inleft+i+1, inright);
        return node;
    }
};
