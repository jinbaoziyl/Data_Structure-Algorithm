#ifndef __BTREE_H__
#define __BTREE_H__
#include "Tree.h"

namespace YLinLib
{
enum BTTraversal
{
    PreOder,
    InOrder,
    PostOrder
}

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
    void preOrderTraversal(BTreeNode<T>*node, LinkQueue<BTreeNode<T>* >&queue)
    {
        if(node != NULL)
        {
            queue.add(node);
            PreOrderTraversal(node->left, queue);
            PreOrderTraversal(node->right, queue);
        }
    }
    void inOrderTraversal(BTreeNode<T>*node, LinkQueue<BTreeNode<T>* >&queue)
    {
        if(node != NULL)
        {
            PreOrderTraversal(node->left, queue);
            queue.add(node);
            PreOrderTraversal(node->right, queue);
        }
    }
    void PostOrderTraversal(BTreeNode<T>*node, LinkQueue<BTreeNode<T>* >&queue)
    {
        if(node != NULL)
        {
            PreOrderTraversal(node->left, queue);
            PreOrderTraversal(node->right, queue);
            queue.add(node);
        }
    } 

    BTreeNode<T> *clone(BTreeNode<T> *node, LinkQueue<BTreeNode<T>* >&queue)
    {
        BTreeNode<T> *ret = NULL;
        if(node != NULL)
        { 
            ret = BTreeNode<T>::NewNode();

            if(ret != NULL)
            {
                ret->value = node->value;

                ret->left = clone(node->left);
                ret->right = clone(node->right);

                if(ret->left != NULL)
                {
                    ret->left->parent = ret;
                }
                if(ret->right != NULL)
                {
                    ret->right->parent = ret;
                }
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No Memory to alloc...");
            }
        }
    }  

    bool equal(BTreeNode<T>* lh, BTreeNode<T>* rh)
    {
        if(lh == rh)
        {
            return true;
        }
        else if(lh != NULL   &&  rh != NULL)
        {
            return (lh->value == rh->value) && equal(lh->right, rh->right)&& equal(lh->left, rh->left);
        }
        else
        {
            return false;
        }
    }

    BTreeNode<T>* add(BTreeNode<T>*lh, BTreeNode<T>*rh) const
    {
        BTreeNode<T>* ret = NULL;

        if( (lh == NULL) && (rh != NULL))
        {
            ret = clone(rh);
        }
        else if( (lh != NULL) && (rh == NULL))
        {
            ret = clone(lh);
        }
        else if((lh != NULL) && (rh != NULL))
        {
            ret = BTreeNode<T>::NewNode();

            if(ret != NULL)
            {
                ret->value = lh->value + rh->value;

                ret->left = add(lh->left, rh->left);
                ret->right = add(lh->right, lh->right);

                if( ret->left != NULL)
                {
                    ret->left->parent = ret;
                }
                if(ret->right != NULL)
                {
                    ret->right->parent = ret;
                }
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No Memory to alloc...");
            }
        }
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

    SharedPointer< Array<T>> traversal(BTTraversal order)
    {
        DynamicArray<T> *ret = NULL;
        LinkQueue<BTreeNode<T> *> queue;
        switch(order)
        {
        case PreOder:
            preOrderTraversal(root(), queue);
            break;
        case InOder:
            inOrderTraversal(root(), queue);
            break;
        case PostOder:
            PostOrderTraversal(root(), queue);
            break;
        default:
            THROW_EXCEPTION(InvalidParameterException, "Parameter order is invalid...");
        }

        ret = new DynamicArray<T>(queue.length());
        if( ret != NULL)
        {
            for(int i=0; i<ret->length(); i++, queue.remove())
            {
                ret->set(i, queue.front()->value);
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No Memory to alloc...");
        }

        return ret;
    }

    SharedPointer< BTree<T>> clone() const
    {
        BTree<T>* ret = new BTree<T>();
        if(ret != NULL)
        {
            ret->m_root = clone(root());
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No Memory to alloc...");
        }

        return ret;
    }

    bool operator == (const BTree<T>& btree)
    {
        return equal(root(), btree.root());
    }
    bool operator != (const BTree<T>& btree)
    {
        return !(*this == btree);
    }

    SharedPointer<BTree<T>> add(const BTree<T>& btree)const
    {
        BTree<T>* ret = new BTree<T>();

        if(ret != NULL)
        {
            ret->m_root = add();
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Parameter order is invalid...");    
        }
    }
    ~BTree()
    {
        clear();
    }
};

}

#endif  //__BTREE_H__