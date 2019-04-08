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

int Ut_BinaryTree(void)
{
    BTreeNode<int>* ns = createTree<int>();

    printInOrder(ns);

    cout << endl;

    return 0;
}

