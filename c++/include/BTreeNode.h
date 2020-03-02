#ifndef __BTREE_NODE_H__
#define __BTREE_NODE_H__
#include "TreeNode.h"

namespace YLinLib
{

template <typename T>
class BTreeNode : public TreeNode
{

public:
    BTreeNode<T>* left;
    BTreeNode<T>* right;

    BTreeNode()
    {
        left = NULL;
        right = NULL;
    }
    static  BTreeNode<T> *NewNode
    {
        BTreeNode<T> *ret = new BTreeNode<T>();

        if(ret != NULL)
        {
            ret->m_flag = true;
        }

        return ret;
    }
};
}

#endif //__BTREE_NODE_H__
