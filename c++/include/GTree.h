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
public:
    bool insert(TreeNode<T> *node)
    {
        bool ret = true;

        return ret;
    }
    bool insert(const T& value, TreeNode<T>* parent)
    {
        bool ret = true;

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
        this->m_root = NULL;
    }

    ~GTree()
    {
        clear();
    }
};
}
#endif //__GTREE_H__