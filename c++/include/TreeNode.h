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
    TreeNode<T> *parent; //根节点->叶节点: 非线性结构;  叶节点->根节点: 线性数据结构(链表)

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
