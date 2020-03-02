#ifndef __LINK_STACK_H__
#define __LINK_STACK_H__
#include "Stack.h"
#include "LinkList.h"

namespace YLinLib
{

template <typename T>
class LinkStack : public Stack
{
protected:
    LinkList<T> m_list;   //内部组合使用LinkList类，实现链式存储
public:
    void push(const T& e)
    {
        m_list.insert(0, e);
    }

    void pop()
    {
        if(m_list.length()>0)
        {
            m_list.remove(0);
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "No element in current stack...");
        }
    }

    T top() const 
    {
        if(m_list.length()>0)
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

    int size() const
    {
        return m_list.length();
    }
};

}

#endif  //__LINK_STACK_H__