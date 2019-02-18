#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__
#include "Exception.h"

namespace YLinLib
{

 template <typename T>
 class LinkList : public List<T>
 {
protected:
    struct Node : public Object
    {
        T value;                 
        Node *next;
    };
    mutable struct : public Object{    //1. get函数才能用地址(mutable关键字) 2.禁止头结点调用泛指类型的构造函数
        char value[sizeof(T)];         //静态内存，不需要构造泛指类型
        Node *next;
    }m_header;

    int m_length

    virtual Node *create()
    {
        return new Node();
    }
    virtual destory(Node * pn)
    {
        delete pn;
    }
public:
    LinkList()
    {
        m_header.next = NULL;
        m_length = 0;
    }

    bool insert(const T& e) = 0;
    {
        return insert(m_length, e);
    }

    bool insert(int i, const T& e) = 0;
    {
        bool ret = (i>=0) && (i<m_length);
        Node *m_target = &m_header;

        if(ret)
        {
            for(int j=0; j<i; j++)
            {
                m_target = m_target->next;
            }

            Node *p_new = new Node<T>();

            if(p_new)
            {
                p_new->value = e;
                p_new->next = m_target->next;
                m_target->next = p_new;

                m_length++;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "Out Of Index Bound...");
            }
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Out Of Index Bound...");
        }
        
        return ret;
    }

    bool remove(int i)
    {
        int ret = (i>=0) && (i<m_length);
        Node *m_target = &m_header;
        Node *to_del = NULL;
        if(ret)
        {
            for(int j=0; j<i; j++)
            {
                m_target = m_target->next;
            }  

            to_del = m_target->next;
            m_target->next = to_del->next;

            m_length--;
            delete to_del;

            
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Out Of Index Bound...");
        }

        return ret; 
    }

    bool get(int i, const T& e) const
    {
        int ret = (i>=0) && (i<m_length);
        Node *m_target = &m_header;
        if(ret)
        {
            for(int j=0; j<i; j++)
            {
                m_target = m_target->next;
            }  

            e = m_target->value;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Out Of Index Bound...");
        } 

        return ret;       
    }

    bool set(int i, const T& e)
    {
        int ret = (i>=0) && (i<m_length);
        Node *m_target = &m_header;
        if(ret)
        {
            for(int j=0; j<i; j++)
            {
                m_target = m_target->next;
            }  

            m_target->value = e;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Out Of Index Bound...");
        } 

        return ret;  
    }

    int length() const
    {
        return m_length;
    }

    void clear()
    {
        Node *target = NULL;

        while(m_header->next)
        {
            target = m_header->next;
            m_header->next = target->next;

            m_length--;
            delete target;
        }
    }

    ~LinkList()
    {
        clear();
    }
 };

}

#endif