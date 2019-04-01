#ifndef __BTREE_H__
#define __BTREE_H__
#include "Tree.h"

namespace YLinLib
{

template <typename T>
class BTree: public Tree
{
public:
    bool insert(TreeNode<T> *node)
    {

    }
    bool insert(const T& value, TreeNode<T>* parent)
    {

    }
    SharedPointer< Tree<T> > remove(const T& value)
    {

    }  
    SharedPointer< Tree<T> > remove(TreeNode<T>* node) 
    {

    }
    TreeNode<T>* find(const T& value) const 
    {

    }
    TreeNode<T>* find(TreeNode<T>* node) 
    {

    }
    TreeNode<T> *root()
    {

    }
    int degree() const
    {

    }
    int count()
    {

    }
    int height()
    {

    }
    void clear()
    {

    }  

    ~BTree()
    {
        clear();
    }
};

}

#endif  //__BTREE_H__