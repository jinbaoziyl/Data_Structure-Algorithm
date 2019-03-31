#ifndef __GTREE_H__
#define __GTREE_H__
#include "Tree.h"
#include "GTreeNode.h"
#include "Exception.h"
#include "LinkQueue.h"

namespace YLinLib
{
template <typename T>
class GTree : public Tree
{
protected:
    LinkQueue<T> m_queue;
    GTreeNode<T>* find(GTreeNode<T>*node, const T& val) const
    {
        GTreeNode<T>*ret = NULL;

        if(node  != NULL)
        {
            if(node->value == val)
            {
                return node;
            }
            else
            {
                for(node->child.move(0), !node->end()&&(ret == NULL); node->child.next()) //遍历当前节点的每一个字树
                {
                    ret = find(node->child.current(), val);
                }
            }
        }
    }
    GTreeNode<T>* find(GTreeNode<T>*node, GTreeNode<T>*obj) const
    {
        GTreeNode<T>*ret = NULL;

        if(node  != NULL)
        {
            if(node == obj)
            {
                return node;
            }
            else
            {
                for(node->child.move(0), !node->end()&&(ret == NULL); node->child.next()) //遍历当前节点的每一个字树
                {
                    ret = find(node->child.current(), obj);
                }
            }
        }
    }

    void free(GTreeNode<T>*node)
    {
        if(node != NULL)
        {
            for(node->child.move(0); node->child.end();node->child.next())//先递归清空字树的节点,再释放自己
            {
               free(node.child.current()); 
            }

            if(node->flag())   //是否堆空间
                delete node;
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Parameter node can no be NULL...");  
        }
    }
    void remove(GTreeNode<T>*node, GTree<T>* &ret)
    {
        ret = new GTree<T>();
        if(ret == NULL)
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No Memory");
        }
        else
        {
            if(root() == node)
            {
                this->m_root = NULL;
            }
            else
            {
                LinkList<GTreeNode<T>*>child = dynamic_cast<GTreeNode<T>*>(node->parent)->child;
                child.remove(child.find(node));
                node->parent = NULL;
            }

            ret->m_root = node;
        }
    }
   /*
                         ---- return 0;             node == NULL
                        |
        count(node) ---------return 1;              node != NULL
                        |
                         ---- count(node->child)+1; node->child.length>0
    */
    int count(GTreeNode<T>*node) const
    {
        int ret = 0;
        if(node == NULL)
        {
            return 0;
        }
        else if(node->child.length == 0)
        {
            return 1;
        }
        else
        {
            ret = 1;
            for(node->child.move(0); !node->child.end();node->child.next())
            {
                ret += count(node->child.current());
            }
        }
        return ret;
    }   

   /*
                         ---- return 0;  node == NULL
                        |
        height(node) --------- return 1;  node->child.length == 0
                        |
                         ---- MAX{height(node->child)}+1; node->child.length>0
    */
    int height(GTreeNode<T>*node) const 
    {
        int ret = 0;
        if(node != NULL)
        {
            for(node->child.move(0); !node->child.end();node->child.next())
            {
                int h = height(node->child.current());

                if(ret < h)
                {
                    ret = h;
                }
            }
            
            ret = ret + 1;
        }

        return ret;
    }

   /*
                         ---- return 0;  node == NULL
                        |
        degree(node) ----
                        |
                         ---- MAX{degree(node->child), node->child.length}; node->child.length>0
    */
    int degree(GTreeNode<T>*node) const 
    {
        int ret = 0;
        if(node != NULL)
        { 
            for(node->child.move(0); !node->child.end();node->child.next())
            {
                ret = node->child.length();
                int d = degree(node->child.current());

                if(ret < d)
                {
                    ret = d;
                }
            }
        }

        return ret;
    }    
public:
    bool insert(TreeNode<T> *node)
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
                GTreeNode<T>* np = find(node->parent);
                if( np != NULL)
                {
                    GTreeNode<T> *n = dynamic_cast<GTreeNode<T>*>(node);
                    if( np->child.find(n) < 0)  //当前查找的节点，不在当前树中; 只需要保证查找到的父节点，它的子节点中是否有当前节点
                    {
                        np->child.insert(n);
                    }
                    else
                    {
                      THROW_EXCEPTION(InvalidParameterException, "Parameter parent node can no already exist...");  
                    }
                }
                else
                {
                    THROW_EXCEPTION(InvalidParameterException, "Parameter parent node can no be null...");
                }
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Parameter node can not be null...");
        }
        return ret;
    }
    bool insert(const T& value, TreeNode<T>* parent)   //插入数据元素，需要指定父节点
    {
        bool ret = true;
        GTreeNode<T>* node = GTreeNode<T>::NewNode();  //使用工厂方法

        if(node != NULL)
        {
            node->value = value;
            node->parent = parent;

            insert(node);
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No Memory to alloc node...");
        }
        return ret;
    }

    /*当需要从函数中返回堆中的对象时，使用函数指针作为返回值*/
    SharedPointer< Tree<T> > remove(const T& value)  //删除的节点及其递归的子树
    {
        GTree<T>* ret = NULL;
        GTreeNode<T>* node = find(value);
        if(node == NULL)
        {
            THROW_EXCEPTION(InvalidParameterException,"can not find value...");
        }
        else
        {
            remove(node, ret);
        }
        return ret;
    }
    SharedPointer< Tree<T> > remove(TreeNode<T>* node)
    {
        GTree<T>* ret = NULL;
        node = find(node);
        if(node == NULL)
        {
            THROW_EXCEPTION(InvalidParameterException,"can not find node...");
        }
        else
        {
            remove(dynamic_cast<GTreeNode *>(node), ret);
        }
        return ret;
    }
    GTreeNode<T>* find(const T& value) const //基于元素值的查找
    {
        return find(root(), value);
    }
    GTreeNode<T>* find(TreeNode<T>* node) const //基于节点的查找
    {
        return find(root(), dynamic_cast<GTreeNode<T>*>(node));
    }
    TreeNode<T> *root() const
    {
        return dynamic_cast<GTreeNode<T>*>(m_root);
    }

    //树的属性: 都是运用递归的思想
    int degree() const
    {
        return degree(root());
    }
    int count() const
    {
        return count(root());
    }
    int height() const
    {
        return height(root());
    }
    void clear()
    {
        free(root());
        this->m_root = NULL;

        m_queue.clear();
    }

    bool begin()
    {
        bool ret = (root() != NULL);
        if(ret)
        {
            m_queue.clear();
            m_queue.add(root());
        }
        return ret;
    }

    bool end()  //队列中没有数据 那么说明遍历结束
    {
        return (m_queue.length == 0);
    }

    bool next()
    {
        bool ret = (m_queue.length > 0);

        if(ret)
        {
            GTreeNode<T> *node = m_queue.front();
            m_queue.remove();

            for(node->child.move(0); !node->child.end(); node->child.next())
            {
                m_queue.add(node->child.current());
            }
        }

        return ret;
    }

    T current()
    {
        if( !end() )  //遍历是否结束
        {
            return m_queue.front()->value;
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException,"No value at this position....");
        }
    }
    ~GTree()
    {
        clear();
    }
};
}
#endif //__GTREE_H__