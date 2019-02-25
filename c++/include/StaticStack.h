/*  1.使用原生数组作为栈的存储空间
*   2.模板参数决定栈的最大容量
*/

#ifndef __STATIC_STACK_H__
#define __STATIC_STACK_H__

namespace YLinLib
{

template <typename T, int N>
class StaticStack : public StaticStack
{
protected:
    T m_space[N];
    int m_top;
    int m_size;
public:
    StaticStack()
    {
        m_top = -1;
        m_size = 0;
    }
    int capacity() const
    {
        return N;
    }

    void push(const T& e)
    {
        if(m_size > N)
        {
            m_space[m_top+1] = e;
            m_top++;
            m_size++;
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "No space to push...");
        }
    }

    void pop()
    {
        if(m_size > 0)
        {
            m_top--;
            m_size--;
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "No space to pop...");
        }
    }

    T top() const
    {
        if(m_size > 0)
        {
            return m_space[m_top];
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "No entry in top...");
        }
    }

    void clear()
    {
        m_top = -1;
        m_size = 0;      
    }

    int size() const
    {
        return m_size;
    }
};

}

#endif //__STATIC_STACK_H__