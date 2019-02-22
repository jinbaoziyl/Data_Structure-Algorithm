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

    int m_length;

    Node *position(int i)
    {
        bool ret = (i>=0) && (i<m_length);
        Node *cur = reinterpret_cast<Node*>(&m_header);
        if(ret)
        {
            for(int j=0; j<i; j++)
            {
                cur = cur->next;
            }

            return cur;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Index out of bound...");
        }
    }

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
        Node *m_target = reinterpret_cast<Node*>(&m_header);

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
        Node *m_target = reinterpret_cast<Node*>(&m_header);
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

    virtual bool get(int i, const T& e) const
    {
        int ret = (i>=0) && (i<m_length);
        Node *m_target = reinterpret_cast<Node*>(&m_header);
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
        Node *m_target = reinterpret_cast<Node*>(&m_header);
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

    virtual bool move(int i, int step = 1)
    {
        bool ret = (i>=0) && (i<m_length) && (step>0);

        if(ret)
        {
            m_current = position(i)->next;
            m_step = step;
        }

        return ret;
    }

    virtual bool end()
    {
        return (m_current == NULL);
    }

    virtual T current()
    {
        if(!end())
        {
            return m_current->value;
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "No value at current position...");
        }
    }

    virtual bool next()
    {
        int i = 0;

        while( (i < m_step) && !end())
        {
            m_current = m_current->next;
            i++
        }

        return (i == m_step);
    }

    ~LinkList()
    {
        clear();
    }
 };

}

#endif