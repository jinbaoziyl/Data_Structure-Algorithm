#ifndef __LINK_STACK_H__
#define __LINK_STACK_H__
#include "Queue.h"
#include "Exception.h"
#include "LinuxList.h"

namespace YLinLib
{
template <typename T>
class LinkQueue : public Queue<T>
{
protected:
    struct Node : public Object
    {
        list_head head;
        T value;
    }

    list_head m_header;
    int m_length;
public:
    LinkQueue()
    {
        m_length = 0;
        LIST_HEAD_INIT(&m_header);
    }

    void add(const T& e)
    {
        Node *node = new Node();
        if(node != NULL)
        {
            node->value = e;
            list_add_tail(&node->header, &m_header);
            m_length++;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to alloc...");
        }
    }

    void remove()
    {
        if(m_length > 0)
        {
            list_head *toDel = m_header->next;

            list_del(toDel);
            m_length--;
            
            delete list_entry(toDel, Node, head);
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "No element in current stack...");
        }       
    }

    T front() const
    {
        if(m_length > 0)
        {
            return list_entry(m_header.next, Node, head)->value;
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "No element in current stack...");
        }        
    }


    void clear()
    {
        while(m_length > 0)
        {
            remove();
        }
    }

    int length() const
    {
        return m_length();
    }

    ~LinkQueue()
    {
        clear();
    }
};

}


#endif   //__LINK_STACK_H__