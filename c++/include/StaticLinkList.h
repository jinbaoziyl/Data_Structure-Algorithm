/*  静态单链表 */
#ifndef __STATIC_LINK_LIST_H__
#define __STATIC_LINK_LIST_H__

namespace YLinLib
{
template <typename T, int N>
class StaticLinkList : public LinkList
{
protected:
    typedef typename LinkList<T>::Node Node;
    struct SNode : Node
    {
        void * operator new (unsigned int size, void *loc)
        {
            (void)size;
            return loc;
        }
    }

    unsigned char m_space[sizeof(SNode) * N];
    int m_used[N];
    Node *create()
    {
        SNode *ret = NULL;

        for(int i=0; i<N; i++)
        {
            if(!m_used[i])
            {
                ret = reinterpret_cast<SNode*>(m_space) + i;
                //泛指类型的构造, 需要使用定义的静态内存  所以需要重载new操作符
                ret = new(ret)SNode();
                m_used[i] = 1;
                break;
            }
        }
        return ret;
    }
    
    destory(Node * pn)
    {
        SNode *space = reinterpret_cast<SNode*>(&m_space);
        SNode *psn = dynamic_cast<Snode*>(pn);  //父类指针转化成子类指针 dynamic_cast

        for(int i=0; i<N; i++)
        {
            if((space + i) == psn)
            {
                m_used[i] = 0;
                psn->~SNode();
                break;
            }
        }
        delete pn;
    }


public:
    StaticLinkList()
    {
        for(int i=0; i<N; i++)
        {
            m_used[i] = 0;
        }
    }
};

    int capacity()
    {
        return N;
    }

    ~StaticLinkList()
    {
        this->clear();
    }
}

#endif //__STATIC_LINK_LIST_H__
