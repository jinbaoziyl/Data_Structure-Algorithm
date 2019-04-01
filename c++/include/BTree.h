#ifndef __BTREE_H__
#define __BTREE_H__
#include "Tree.h"

namespace YLinLib
{

template <typename T>
class BTree: public Tree
{
protected:
    BTreeNode<T>* find(BTreeNode<T>* node,const T& value) const 
    {
        BTreeNode<T>* ret = NULL;
        if(node != NULL)
        {
            if(node->value == value)
            {
                ret = node;
            }
            else
            {
                if(ret == NULL)
                    ret = find(node->left, value);
                if(ret == NULL)
                    ret = find(node->right,value);
            }
        }
        return ret;
    }

    BTreeNode<T>* find(BTreeNode<T>* node,BTreeNode<T>* obj) const 
    {
        BTreeNode<T>* ret = NULL;
        if(node != obj)
        {
            if(node == obj)
            {
                ret = node;
            }
            else
            {
                if(ret == NULL)
                    ret = find(node->left, value);
                if(ret == NULL)
                    ret = find(node->right,value);
            }
        }

        return ret;
    }
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
    BTreeNode<T>* find(const T& value) 
    {
        return find(root(),value);
    }
    BTreeNode<T>* find(TreeNode<T>* node) 
    {
        return find(root(),node);
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