

#ifndef __DYNAMIC_ARRAY_H__
#define  __DYNAMIC_ARRAY_H__
#include "Exception.h"

namespace YLinLib
{

template <typename T>
class DynamicArray : public Array<T>
{
protected:
    int length;
public:
    DynamicArray(int len)
    {
        m_array = new T[len];

        if(m_array != NULL)
        {
            this->length = len;
        }
        else
        {
            /* 抛出异常 */
            THROW_EXCEPTION(NoEnoughMemoryException, "No Memory to alloc...");
        }
        
    }
    
    DynamicArray(const DynamicArray<T>& obj)
    {
        T *p = new T[obj.length];

        if(p != NULL)
        {
            for(int i=0; i<obj.length; i++)
            {
                p[i] = obj.m_array[i];
            }

            this->length  = obj.length;
            this->m_array = p;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No Memory to alloc...");
        }
        
    }

    DynamicArray<T>& operator= (const DynamicArray<T>& obj)
    {
        if(this != &obj)
        {
            T *p = new T[obj.length];
            if(p != NULL)
            {
                for(int i=0; i<obj.length; i++)
                {
                    p[i] = obj.m_array[i];
                }

                T *p_tmp = this->m_array;

                this->length  = obj.length;
                this->m_array = p;

                delete[] p_tmp;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No Memory to alloc...");
            }          
        }

        return *this;
    }

    void resize(int len)
    {
        if(len != this->length)
        {
            int size = (len > this->length) ? this->length : len;

            T *p = new T[size];
            if(p != NULL)
            {
                for(int i=0; i<size; i++)
                {
                    p[i] = (this->m_array)[i];
                }

                T* p_tmp = this->m_array;

                this->length = size;
                this->m_array = p;

                delete[] p_tmp;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No Memory to alloc...");
            }    
        }
    }

    int length() const
    {
        return length;
    }

    ~DynamicArray()
    {
        delete[] m_array;
    }
}

}

#endif //__DYNAMIC_ARRAY_H__