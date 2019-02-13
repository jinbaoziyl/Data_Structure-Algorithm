/*   智能指针三个要点: 
*     1. 智能生命周期结束  主动释放堆空间
*     2. 一片堆空间 最多智能由一个指针指向
*     3. 杜绝指针比较和运算
*/
#ifndef __SMART_POINTER_H__
#define __SMART_POINTER_H__
#include "Object.h"

#include <stdio.h>
namespace YLinLib
{

template<typename T>
class SmartPointer : public Object
{
protected:
    T *m_pointer;
public:
    SmartPointer(T *p = NULL)
    {
        m_pointer = p;
    }

    SmartPointer(const SmartPointer<T>& p)
    {
        m_pointer = p.m_pointer;
        const_cast<SmartPointer<T>&>(p).m_pointer = NULL;
    }

    SmartPointer<T>& operator=(const SmartPointer<T>& p)
    {
        if(this != &p)  // 判断是否是自赋值
        {
            delete m_pointer; // 删除原有内存

            m_pointer = p.m_pointer; //实际赋值操作
            const_cast<SmartPointer<T>&>(p).m_pointer = NULL;
        }
        return *this;  // 返回自身，支持继续赋值
    }

    T* operator-> ()
    {
        return m_pointer;
    }

    T& operator* ()
    {
        return *m_pointer;
    }

    bool isNull()
    {
        return (m_pointer == NULL);
    }

    T* get()
    {
        return m_pointer;
    }

    ~SmartPointer()
    {
        delete m_pointer;
    }
};

}

#endif