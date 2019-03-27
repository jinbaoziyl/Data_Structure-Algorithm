#ifndef __GTREE_H__
#define __GTREE_H__

namespace YLinLib
{
template <typename T>
class GTree : public Tree
{
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
    GTreeNode<T>* find(const T& value) const
    {
        return NULL;
    }
    GTreeNode<T>* find(TreeNode<T>* node) const
    {
        return NULL;
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