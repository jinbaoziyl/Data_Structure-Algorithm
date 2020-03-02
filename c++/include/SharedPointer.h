#ifndef __SHARED_POINTER_H__
#define __SHARED_POINTER_H__

namespace YLinLib
{
template <typename T>
class SharedPointer : public Pointer
{
protected:
    int *m_ref;   //计数机制成员指针
public:
    SharedPointer(T *p = NULL) : m_ref(NULL)
    {
       if(p != NULL)
       {
           m_ref = new int();
           if(m_ref != NULL)
           {
                *m_ref = 1;
                this->m_pointer = p;
           }
           else
           {
               THROW_EXCEPTION(NoEnoughMemoryException, "No Memory to alloc...")
           }
       }
    }

    SharedPointer(const SharedPointer<T>& obj)   //创建多一个指针指向同一堆空间
    {
        this->m_pointer = obj.m_pointer;
        this->m_ref     = obj.m_ref;

        if(this->m_ref)
        {
            (*this->m_ref)++;
        }
    }   

    SharedPointer<T>& operator= (const SharedPointer<T>& obj)
    {
        if(this != &obj)
        {
            //处理原来指向堆空间的问题: 将当前的智能指针置空
            clear();
            //赋值操作
            this->m_pointer = obj.m_pointer;
            this->m_ref     = obj.m_ref;

            if(this->m_ref)
            {
                (*this->m_ref)++;
            }
        }

        return *this;
    } 

    void clear()   //将当前指针置空
    {
        T *toDel = this->m_pointer;
        int *ref = this->m_ref;

        this->m_pointer = NULL;
        this->m_ref = NULL;

        if(ref)
        {
            (*ref)--;

            if(*ref == 0)
            {
                delete ref;
                delete toDel;
            }
        }
    }

    ~SharedPointer()
    {
        clear();
    }
};

}
#endif //__SHARED_POINTER_H__
