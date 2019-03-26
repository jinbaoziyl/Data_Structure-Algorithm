#ifndef __TREE_NODE_H__
#define __TREE_NODE_H__
#include "Object.h"

namespace YLinLib
{

template <typename T>
class TreeNode : public Object
{
public:
    T value;
    TreeNode<T> *parent;

    TreeNode()
    {
        parent = NULL;
    }

    virtual ~TreeNode() = 0;
};
template <typename T>
TreeNode<T>::~TreeNode()
{
    
}

}
#endif
