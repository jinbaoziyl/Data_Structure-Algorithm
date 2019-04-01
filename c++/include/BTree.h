#ifndef __BTREE_H__
#define __BTREE_H__
#include "Tree.h"

namespace YLinLib
{

enum BTNodePos
{
    ANY,
    LEFT,
    RIGHT
};

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

    virtual bool insert(BTreeNode<T>*n, BTreeNode<T>*np, BTNodePos pos)
    {
        bool ret = true;

        if(pos == ANY)
        {
            if(np->left == NULL)
                np->left = n;
            else if(np->right == NULL) 
                np->right = n;
            else
                ret = false;
        }
        else if(pos == LEFT)
        {
            if(np->left == NULL)
                np->left = n;
            else
                ret = false;  
        }
        else if(pos == RIGHT)
        {
            if(np->right == NULL)
                np->right = n;
            else
                ret = false;  
        }

        else
        {
            return false;
        }

        return ret;
    }
public:
    bool insert(TreeNode<T> *node)
    {
        return insert(node, ANY);
    }
    bool insert(TreeNode<T> *node, BTNodePos pos)
    {
        bool ret = true;

        if(node != NULL)
        {   
            if(this->m_root == NULL)
            {
                node->parent = NULL;
                this->m_root = node;
            }
            else
            {
                TreeNode<T> *np = find(node->parent);

                if(np != NULL)
                {
                    ret = insert(dynamic_cast<BTreeNode<T> *>(node), np, pos);
                }
                else
                {
                    THROW_EXCEPTION(InvalidParameterException, "Invalid pos to insert..."):
                }
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Invalid node input...");
        }
    }
    bool insert(const T& value, TreeNode<T>* parent, BTNodePos pos)
    {
        bool ret = true;
        BTreeNode<T> *node = BTreeNode<T>::NewNode();

        if(node == NULL)
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No Memory to alloc...");
        }
        else
        {
            node->value = value;
            node->parent = parent;

           ret = insert(node,pos); 
           if(!ret)
           {
               delete node;
           }
        }

        return ret;
    }
    bool insert(const T& value, TreeNode<T>* parent)
    {
        return insert(value, parent, ANY);
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