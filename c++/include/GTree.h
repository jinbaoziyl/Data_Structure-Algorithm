#ifndef __GTREE_H__
#define __GTREE_H__

namespace YLinLib
{
template <typename T>
class GTree : public Tree
{
protected:
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
    SharedPointer< Tree<T> > remove(const T& value)  //删除的节点及其递归的子树，一起返回智能指针
    {
        return NULL;
    }
    SharedPointer< Tree<T> > remove(TreeNode<T>* node)
    {
        return NULL;
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
    int degree() const
    {
        return 0;
    }
    int count() const
    {
        return 0;
    }
    int height() const
    {
        return 0;
    }
    void clear()
    {
        free(root());
        this->m_root = NULL;
    }

    ~GTree()
    {
        clear();
    }
};
}
#endif //__GTREE_H__