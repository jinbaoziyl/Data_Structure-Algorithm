#ifndef __LINK_STACK_H__
#define __LINK_STACK_H__
#include "Queue.h"
#include "Exception.h"
#include "LinkList.h"

namespace YLinLib
{
template <typename T>
class LinkQueue_BaseList : public Queue<T>
{
protected:
    LinkList<T> m_list;
public:
    LinkQueue_BaseList()
    {

    }

    void add(const T& e)
    {
        if(m_length < N)
        {
            m_list.insert(e);
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "No element in current stack...");
        }
    }

    void remove()
    {
        if(m_length > 0)
        {
            m_list.remove(0);
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
            return m_list.get(0);
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "No element in current stack...");
        }        
    }


    void clear()
    {
        m_list.clear();
    }

    int length() const
    {
        return m_list.length();
    }
};

}


#endif   //__LINK_STACK_H__