/*   1.使用原生数组作为队列存储空间
     2.模板参数决定队列的最大容量
*/
#ifndef __STATIC_QUEUE_H__
#define __STATIC_QUEUE_H__
#include "Queue.h"
#include "Exception.h"

namespace YLinLib
{
template <typename T, int N>
class StaticQueue : public StaticQueue
{
protected:
    T m_space[N];
    int m_front;
    int m_rear;
    int m_length;
public:
    StaticQueue()
    {
        m_front = 0;
        m_rear = 0;
        m_length = 0;
    }

    void add(const T& e)
    {
        if(m_length < N)
        {
            m_space[m_rear] = N;
            m_rear = (m_rear + 1) % N;
            m_length++;
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
            m_front = (m_front + 1) % N;
            m_length--;
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
            return m_space[m_front];
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "No element in current stack...");
        }        
    }

    int capacity() const
    {
        return N;
    }

    void clear()
    {
        m_front = 0;
        m_rear = 0;
        m_length = 0;       
    }

    int length() const
    {
        return m_length;
    }
};

}

#endif //__STATIC_QUEUE_H__