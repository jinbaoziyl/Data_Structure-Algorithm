/* 创建数组类 代替原生数组
*     1. 抽象模板类   存储空间大小由子类定义
*     2. 重载数组操作符 判断访问下标是否合法
*     3. 提供数组长度的 抽象访问方法
*     4. 提供数组对象间 复制操作
*/
#ifndef __ARRAY_H__
#define __ARRAY_H__

namespace YLinLib
{

template <typename T>
class Array : public Object
{
protected:
    T *m_array;
public:
    virtual bool set(int i, const T& e)
    {
        bool ret = (i>=0) && (i<length());

        if(ret)
        {
            m_array[i] = e;
        }
        return ret;
    }
    virtual bool get(int i, const T& e) const
    {
        bool ret = (i>=0) && (i<length());

        if(ret)
        {
            e = m_array[i];
        }
        return ret;
    }

    virtual int length() const= 0;

    //数组访问操作符
    T& operator[] (int i)
    {
        if((i>=0) && (i<length()))
        {
            return m_array[i];
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No Memory to alloc...");
        }
    }

    T  operator[] (int i ) const
    {
        return (const_cast<Array<T>& >(*this))[i];
    }
};

}

#endif //__ARRAY_H__
