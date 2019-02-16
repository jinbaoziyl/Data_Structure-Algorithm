#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__
#include "Exception.h"

namespace YLinLib
{

 template <typename T>
 class LinkList : public LinkList<T>
 {
protected:
    struct Node : public Object
    {
        char value[sizeof(T)];
        Node *next;
    };
    mutable struct Node m_header;   //get函数 才能用地址(mutable关键字)
    int m_length
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
            memcpy(p_new->value, &e, sizeof(T));

            p_new->next = m_target->next;
            m_target->next = p_new;

            m_length++;
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
            delete to_del;

            m_length--;
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
            delete target;
        }

        m_length = 0;
    }

    ~LinkList()
    {
        clear();
    }
 };

}

#endif