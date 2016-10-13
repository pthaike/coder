/**
http://hihocoder.com/contest/hiho103/problem/1
��Ŀ1 : ƽ������Treap
ʱ������:10000ms
����ʱ��:1000ms
�ڴ�����:256MB
����

СHo��СHi���ҷ���������ǰ�������������ݽṹ�ر����ơ�

СHi����˵��������������

СHo�����Ƕ����������ͶѰ����㿴���������ݽṹ���ǹ�����һ����������һ���ڵ���һ�����׺��������ӡ� �����1..n���������洢�Ļ������ڶ������ϵ�һ�����Ϊk�Ľڵ㣬�丸�׽ڵ�պ���k/2�����������������ӽڵ�ֱ�Ϊk*2��k*2+1�����������ǳ������ء�

СHi��û������СHi��֪����һ�ְ취���԰ѶѺͶ����������ϲ���������Ϊһ���µ����ݽṹô��

СHo�����ҵ�û�����������������������������<���ڵ�<��������������������ڵ�С�ڵ���(����ڵ���)���Ҷ��ӡ������������ǳ�ͻ�İ���

СHi��������˵��û�����������ʵ�ȷ�ǳ�ͻ�ġ�

СHo������˵�ĺϲ�����ô�����ģ�

СHi����Ȼ�а취�ˣ���ʵ����������....

��ʾ��Tree+Heap?

����

��1�У�1��������n����ʾ����������10��n��100,000

��2..n+1�У�ÿ��1����ĸc��1������k��

��cΪ'I'����ʾ����һ������k�����У�-1,000,000,000��k��1,000,000,000

��cΪ'Q'����ʾѯ�����в�����k���������

���

�����У�ÿ��1����������ʾ���ѯ�ʵĻش𣬱�֤һ���кϷ��Ľ�

��������
5
I 3
I 2
Q 3
I 5
Q 4
�������
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

//����
void leftRotate(struct _node *& a)
{
    struct _node * b = a->right;
    a->right = b->left;
    b->left = a;
    a = b;
}

//����
void rightRotate(struct _node *& a)
{
    struct _node * b = a->left;
    a->left = b->right;
    b->right = a;
    a = b;
}

//����
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


//��ѯ
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
