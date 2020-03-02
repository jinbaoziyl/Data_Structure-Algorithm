/* 通过两个队列实现栈
    1.准备两个队列   queue_in,queue_out
    2.当有新数据到来时， 加入queue_in
    3.当需要出栈时：
        queue_in的前n-1个元素出队列，放到queue_out中
        弹出queue的第n个数据
        交换两个队列的角色
*/
#ifndef __QUEUE_TO_SATCK_H__
#define __QUEUE_TO_SATCK_H__

namespace YLinLib
{

template <typename T>
class QueueToStack : public Stack<T>
{
protected:
    LinkQueue<T> m_queue1;
    LinkQueue<T> m_queue2;
    LinkQueue<T>* m_qIn;   //角色
    LinkQueue<T>* m_qOut;

    void move()
    {
        int n = m_qIn->length() -1;
        for(int i=0; i<n; i++)
        {
            m_qOut->add(m_qIn.front());
            m_qIn.remove();
        }
    }

    void swap()
    {
        LinkQueue<T>* m_tmp = NULL;

        m_tmp = m_qIn;
        m_qIn = m_qOut;
        m_qOut = m_tmp;
    }
public:
    QueueToStack()
    {
        m_qIn = &m_queue1;
        m_qOut = &m_queue2;
    }

    void push(const T& e)
    {
        m_qIn.add(e);
    }

    void pop()
    {
        if(m_qIn.length() > 0)
        {
            move();
            m_qIn.remove();

            swap();
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "No element to pop...");
        }
    }

    T top() const
    {
        if(m_qIn.length() > 0)
        {
            move();
            return m_qIn.front();
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "No element to pop...");
        }
    }

    void clear()
    {
        m_queue1.clear();
        m_queue2.clear();
    }

    int size() const 
    {
        return (m_queue1.size() + m_queue2.size());
    }
};

}

#endif //__QUEUE_TO_SATCK_H__