#ifndef __GTREE_NODE_H__
#define __GTREE_NODE_H__
#include "LinkList.h"
#include "TreeNode.h"

/* 工厂模式：区分堆中节点或是栈中节点；以免在清除操作中对栈中对象进行delete
 1) 在GTreeNode中增加保护成员变量m_flag
 2) GTreeNode中的operator new重载为保护成员函数
 3) 提供工程方法(静态成员函数): GTreeNode<T> *NewNode
 4) 在工程方法中new新节点，并将m_flag设置为true
*/
namespace YLinLib
{

template <typename T>
class GTreeNode : public TreeNode
{
protected:
    bool m_flag;

    GTreeNode(const GTreeNode<T>&);
    GTreeNode<T>& operator = (const GTreeNode<T&);
    //重载new操作符
    void* operator new(unsigned int size) throw()
    {
        return Object::operator new(size);
    }
public:
    LinkList<GTreeNode<T>* >child;

    GTreeNode()
    {
        m_flag = false;
    }

    bool flag()
    {
        return m_flag;
    }
    static  GTreeNode<T> *NewNode
    {
        GTreeNode<T> *ret = new GTreeNode<T>();

        if(ret != NULL)
        {
            ret->m_flag = true;
        }

        return ret;
    }
};
}

#endif //__GTREE_NODE_H__