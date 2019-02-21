/*   智能指针三个要点: 
*     1. 智能生命周期结束  主动释放堆空间
*     2. 一片堆空间 最多智能由一个指针指向
*     3. 杜绝指针比较和运算
*/
#ifndef __SMART_POINTER_H__
#define __SMART_POINTER_H__
#include "Pointer.h"

#include <stdio.h>
namespace YLinLib
{

template<typename T>
class SmartPointer : public Pointer
{
public:
    SmartPointer(T *p = NULL) : Pointer<T>(p)
    {

    }

    SmartPointer(const SmartPointer<T>& p)
    {
        this->m_pointer = p.m_pointer;
        const_cast<SmartPointer<T>&>(p).m_pointer = NULL;
    }

    SmartPointer<T>& operator=(const SmartPointer<T>& p)
    {
        if(this != &p)  // 判断是否是自赋值
        {
            T *p = m_pointer;  //放在后面 删除指针，异常安全

            this->m_pointer = p.m_pointer; //实际赋值操作
            const_cast<SmartPointer<T>&>(p).m_pointer = NULL;

            delete p;
        }
        return *this;  // 返回自身，支持继续赋值
    }

    ~SmartPointer()  //该类不再是抽象类，需要实现纯虚析构函数
    {
        delete this->m_pointer;
    }
};

}

#endif