#include <iostream>
#include "BTreeNode.h"

using namespace std;
using namespace DTLib;

template < typename T >
BTreeNode<T>* createTree()
{
    static BTreeNode<int> ns[9];

    for(int i=0; i<9; i++)
    {
        ns[i].value = i;
        ns[i].parent = NULL;
        ns[i].left = NULL;
        ns[i].right = NULL;
    }

    ns[0].left = &ns[1];
    ns[0].right = &ns[2];
    ns[1].parent = &ns[0];
    ns[2].parent = &ns[0];

    ns[1].left = &ns[3];
    ns[1].right = NULL;
    ns[3].parent = &ns[1];

    ns[2].left = &ns[4];
    ns[2].right = &ns[5];
    ns[4].parent = &ns[2];
    ns[5].parent = &ns[2];

    ns[3].left = NULL;
    ns[3].right = &ns[6];
    ns[6].parent = &ns[3];

    ns[4].left = &ns[7];
    ns[4].right = NULL;
    ns[7].parent = &ns[4];

    ns[5].left = &ns[8];
    ns[5].right = NULL;
    ns[8].parent = &ns[5];

    return ns;
}

template < typename T >
void printInOrder(BTreeNode<T>* node)
{
    if( node != NULL )
    {
        printInOrder(node->left);

        cout << node->value <<" ";

        printInOrder(node->right);
    }
}

template < typename T >
void printDualList(BTreeNode<T>* node)
{
    BTreeNode<T>* g = node;

    cout << "head -> tail: " << endl;

    while( node != NULL )
    {
        cout << node->value << " ";

        g = node;

        node = node->right;
    }

    cout << endl;

    cout << "tail -> head: " << endl;

    while( g != NULL )
    {
        cout << g->value << " ";

        g = g->left;
    }

    cout << endl;
}

/* 单度结点删除: 结点包含父节点的情况 */
template < typename T >
BTreeNode<T> *delOdd1(BTreeNode<T>* node)
{
    BTreeNode<T>* ret = NULL;
    if( node != NULL)
    {
        if( ((node->left != NULL) && (node->right == NULL)) ||
            ((node->left == NULL) && (node->right != NULL)))
        {
            BTreeNode<T>* parent = dynamic_cast<BTreeNode<T>*>(node->parent);
            BTreeNode<T>* node_child = (node->left != NULL) ? node->left : node->right;

            if(parent != NULL)
            {
                BTreeNode<T>* &parent_child = (parent->left == node) ? parent->left:node->right;
                parent_child = node_child;

                node_child->parent = parent;
            }
            else
            {
                node_child->parent = NULL;
            }

            if(node->flag())
            {
                delete node;
            }

            ret = delOdd1(node_child);
        }
        else
        {
            delOdd1(node->left);
            delOdd1(node->right);

            ret = node;
        }
    }
}


/* 单度结点删除 : 结点不包含父节点的情况 */
template < typename T >
void delOdd2(BTreeNode<T>* node)
{
    if( node != NULL)
    {
        if( ((node->left != NULL) && (node->right == NULL)) ||
            ((node->left == NULL) && (node->right != NULL)))
        {
            BTreeNode<T>* node_child = (node->left != NULL) ? node->left : node->right;

            if(node->flag())
            {
                delete node;
            }
            node = node_child;
            delOdd2(node);
        }
        else
        {
            delOdd2(node->left);
            delOdd2(node->right);
        }
    }
}

/* @pre: 中序遍历时，前驱结点的指针*/
template <typename T>
BTreeNode<T>* inOrderThread(BTreeNode<T>* node, BTreeNode<T>* &pre)
{
    if(node != NULL)
    {
        inOrderThread(node->left, pre);

        node->left = pref;
        if(pre != NULL)
        {
            pref->right = node;
        }

        pre = node;

        inOrderThread(node->right, pre);
    }
}
/* 具体的线索化函数 */
template <typename T>
BTreeNode<T>* inOrderThread_Impl1(BTreeNode<T>* node)
{
    BTreeNode<T>* pre = NULL;

    inOrderThread(node, pre);
    while( (node != NULL) && (node->left != NULL))   //向前循环查找，头结点
    {
        node = node->left;
    }

    return node;
}

/* 中序遍历的结点次序正好是结点的水平次序 */
/* @node: 根节点， 也是中序访问的结点
*  @head: 转换成功后，指向双向链表的首结点
*  @tail: 转换成功后，指向双向链表的尾结点
*/
template <typename T>
BTreeNode<T>* inOrderThread(BTreeNode<T>* node, BTreeNode<T>* &head, BTreeNode<T>* &tail)
{
    if(node != NULL)
    {
        BTreeNode<T> *h = NULL;
        BTreeNode<T> *t = NULL;
        inOrderThread(node->left, h, t);

        node->left = t;
        if(t != NULL)
        {
            t->right = node;
        }

        head = (h != NULL) ? h:node; //左子树最左边的指针

        inOrderThread(node->right, h, t);
        node->right = t;
        if(h != NULL)
        {
            t->left = node;
        }

        tail = (t != NULL) ? t:node; //右子树最右边的指针
    }
}
template <typename T>
BTreeNode<T>* inOrderThread_Impl2(BTreeNode<T>* node)
{
    BTreeNode<T>* head = NULL;
    BTreeNode<T>* tail = NULL;

    inOrderThread(node, head, tail);
    inOrderThread(node, head, tail);

    return head;
}

int Ut_BinaryTree(void)
{
    BTreeNode<int>* ns = createTree<int>();

    printInOrder(ns);

    cout << endl;

    return 0;
}

