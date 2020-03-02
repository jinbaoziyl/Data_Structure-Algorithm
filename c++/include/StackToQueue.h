/*  通过两个栈实现队列
    1. 准备两个栈，分别入栈和出栈 stack_in, stack_out
    2. 当需要入栈时，将其压入stack_in
    3. 当需要出栈时
            如果stack_out长度是0，那么需要从stack_in中倒出数据到stack_out
            如果stack_out长度非0，直接弹出数据
*/
#ifndef __STACK_TO_QUEUE_H__
#define __STACK_TO_QUEUE_H__
#include "LinkStack.h"
#include "LinkQueue.h"
namespace YLinLib
{

template <typename T>
class StackToQueue :  public Queue<T>
{
protected:
    mutable LinkStack<T> m_stack_in;      //因为move函数是const, 又有pop、push等，所以应该用关键字mutable, stack才不会收到限制
    mutable LinkStack<T> m_stack_out;

    void move()  const
    {
        if(m_stack_out.size() == 0)   //当out栈为空时，从in栈中倒出数据
        {
            while(m_stack_in.size())
            {
                m_stack_out.push(m_stack_in.top());
                m_stack_in.pop();
            }
        }
    }
public:
    void push(const T& e)
    {
        m_stack_in.push(e);
    }

    void pop() 
    {
        move();   //因为pop是const，所以move函数也应该是const
        if(m_stack_out.size() > 0)
        {
            m_stack_out.pop();
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "No element to pop...");
        }
    }

    T top() const 
    {
        move();   

        if(m_stack_out.size() > 0)
        {
            return m_stack_out.top();
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "No element to pop...");
        }
    }

    void clear() 
    {
        m_stack_in.clear();
        m_stack_out.clear();
    }

    int size() const 
    {
        return (m_stack_in.size() + m_stack_out.size());
    }

};

}

#endif //__STACK_TO_QUEUE_H__