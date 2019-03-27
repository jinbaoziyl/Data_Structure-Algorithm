#ifndef __GTREE_NODE_H__
#define __GTREE_NODE_H__
#include "LinkList.h"
#include "TreeNode.h"

namespace YLinLib
{

template <typename T>
class GTreeNode : public TreeNode
{
public:
    LinkList<GTreeNode<T>* >child;
};

}
#endif //__GTREE_NODE_H__