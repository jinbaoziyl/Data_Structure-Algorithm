/* 智能指针抽象父类
               Object
                  |
                  |
               Pointer
               /    \
              /      \
    SmartPointer   SharedPointer 
*/
#ifndef __POINTER_H__
#define __POINTER_H__

namespace YLinLib
{

template <typename T>
class Pointer : public Object
{
protected:
    T *m_pointer;

public:
    Pointer(T *p = NULL)
    {
        m_pointer = p;
    }
    T* operator->()
    {
        return m_pointer;
    }
    T& operator* ()
    {
        return *m_pointer;
    }
    bool isNULL()
    {
        return (m_pointer == NULL);
    }
    T* get()
    {
        return m_pointer;
    }
    //析构函数是继承之Object的纯虚函数
};

}

#endif //__POINTER_H__