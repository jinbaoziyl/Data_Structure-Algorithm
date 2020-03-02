/* 1. 申请连续堆空间作为顺序存储的空间
*  2. 动态设置存储空间的大小
*  3. resize空间大小时，保证异常安全性
*/
#ifndef __DYNAMIC_LIST_H__
#define __DYNAMIC_LIST_H__

#include "Exception.h"
namespace YLinLib
{

template <typename T>
class DynamicList : public SeqList<T>
{
protected:
    int capacity;
public:
    DynamicList(int capacity);
    {
        this->m_array = new T[capacity];

        if(this->m_array != NULL)
        {
            this->m_length = 0;
            this->capacity = capacity;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No Memory to alloc...");
        }
    }

    int capacity() const
    {
        return capacity;
    }

    void resize(int capacity)
    {
        if(capacity != this->capacity)
        {
            int len = (capacity > this->m_length) ? this->m_length : capacity;

            T *p_tmp = new T[capacity];
            if(p_tmp != NULL)
            {
                for(int i=0; i< this->m_length; i++)
                {   
                    p_tmp[i] = this->m_array[i];
                }

                T *p = this->m_array;
                
                this->m_array = p_tmp;
                this->m_length = len;
                this->capacity = capacity;

                delete[] p;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No Memory to alloc...");
            }
        }
    }

    ~DynamicList()
    {
        delete[] m_array;
        m_length = 0;
    }
};

}

#endif //__DYNAMIC_LIST_H__