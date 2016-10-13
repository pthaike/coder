/**
http://hihocoder.com/contest/hiho103/problem/1
题目1 : 平衡树·Treap
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述

小Ho：小Hi，我发现我们以前讲过的两个数据结构特别相似。

小Hi：你说的是哪两个啊？

小Ho：就是二叉排序树和堆啊，你看这两种数据结构都是构造了一个二叉树，一个节点有一个父亲和两个儿子。 如果用1..n的数组来存储的话，对于二叉树上的一个编号为k的节点，其父亲节点刚好是k/2。并且它的两个儿子节点分别为k*2和k*2+1，计算起来非常方便呢。

小Hi：没错，但是小Hi你知道有一种办法可以把堆和二叉搜索树合并起来，成为一个新的数据结构么？

小Ho：这我倒没想过。不过二叉搜索树满足左子树<根节点<右子树，而堆是满足根节点小于等于(或大于等于)左右儿子。这两种性质是冲突的啊？

小Hi：恩，你说的没错，这两种性质的确是冲突的。

小Ho：那你说的合并是怎么做到的？

小Hi：当然有办法了，其实它是这样的....

提示：Tree+Heap?

输入

第1行：1个正整数n，表示操作数量，10≤n≤100,000

第2..n+1行：每行1个字母c和1个整数k：

若c为'I'，表示插入一个数字k到树中，-1,000,000,000≤k≤1,000,000,000

若c为'Q'，表示询问树中不超过k的最大数字

输出

若干行：每行1个整数，表示针对询问的回答，保证一定有合法的解

样例输入
5
I 3
I 2
Q 3
I 5
Q 4
样例输出
3
3

*/

#include<cstdio>
#include<cmath>
#include<cstdlib>

using namespace std;

struct _node
{
    struct _node * left;
    struct _node * right;
    int key;
    int priority;
    _node(int k):left(NULL), right(NULL), key(k), priority(rand()){};
};

//左旋
void leftRotate(struct _node *& a)
{
    struct _node * b = a->right;
    a->right = b->left;
    b->left = a;
    a = b;
}

//右旋
void rightRotate(struct _node *& a)
{
    struct _node * b = a->left;
    a->left = b->right;
    b->right = a;
    a = b;
}

//插入
void insert(struct _node *& root, int key)
{
    if(!root)
    {
        root = new _node(key);
        return;
    }
    if(key < root->key)
    {
        insert(root->left, key);
        if(root->priority > root->left->priority)
                rightRotate(root);
    }
    else
    {
        insert(root->right, key);
        if(root->priority > root->right->priority)
            leftRotate(root);
    }
}


//查询
int query(struct _node * root, int key)
{
    struct _node * p = root;
    int res = 0;
    while(p)
    {
        if(p->key == key) return key;
        else if(p->key < key)
        {
            res = p->key;
            p = p->right;
        }
        else
            p = p->left;
    }
    return res;
}


int main(void)
{
    int n,c,k;
    scanf("%d",&n);
    struct _node * root = NULL;
    while(n--)
    {
        scanf("%c%c%d", &c,&c,&k);
        if(c == 'I')
            insert(root, k);
        else
            printf("%d\n", query(root, k));
    }
    return 0;
}
