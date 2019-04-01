#ifndef __TREE_H__
#define __TREE_H__
#include "TreeNode.h"
#include "SharedPointer.h"
namespace YLinLib
{

template <typename T>
class Tree : public Object
{
protected:
    TreeNode<T> *m_root;

    Tree(const Tree<T>&);
    Tree<T>& operator = (const Tree<T>&);
public:
    Tree() {m_root = NULL;}
    virtual bool insert(TreeNode<T> *node) = 0;
    virtual bool insert(const T& value, TreeNode<T>* parent) = 0;
    virtual SharedPointer< Tree<T> > remove(const T& value) = 0;   //删除的节点及其递归的子树，一起返回智能指针
    virtual SharedPointer< Tree<T> > remove(TreeNode<T>* node) = 0;
    virtual TreeNode<T>* find(const T& value) const = 0;
    virtual TreeNode<T>* find(TreeNode<T>* node) const = 0;
    virtual TreeNode<T> *root() const = 0;
    virtual int degree() const = 0;
    virtual int count() const = 0;
    virtual int height() const = 0;
    virtual void clear() = 0;
};
 
}

#endif //__TREE_H__