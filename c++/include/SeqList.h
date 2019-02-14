/*  顺序存储 线性表
           List
             |
           SeqList
           /     \
          /       \
    StaticList   DynamicList
*/

#ifndef __SEQLIST_H__
#define __SEQLIST_H__

namespace YLinLib
{

template <typename T>
class SeqList : public List<T>  //抽象模板类，存储空间的位置和大小应该由子类来完成
{
protected:
    T *m_array;    //空间
    int m_length;  //大小
public:
    bool insert(int i, const T& e)
    {
        bool res = (i < m_length)&&(i >= 0);
        res = res && ((m_length + 1) <= capacity());
        if(res)
        {
            for(int p = m_length-1; p > i; p--)
            {
                m_array[p+1] = m_array[p];
            }
            m_array[i] = e;
            m_length++;
        }
        return res;        
    }

    bool remove(int i)
    {
        bool res = (i < m_length)&&(i >= 0);
        if(res)
        {
            for(int p=i; p<m_length-1; p++)
            {
                m_array[p] = m_array[p+1];
            }
            m_length--;
        }

        return res;
    }

    bool get(int i, const T& e) const
    {
        bool res = (i<m_length)&&(i>=0);
        //e = *(m_array + sizeof(T)*i);
        if(res)
            e = m_array[i];
        return res;
    }
    bool set(int i, const T& e)
    {
        bool res = (i<m_length)&&(i>=0);
        //memcpy(m_array + sizeof(T)*i, &e, sizeof(T));
        if(res)
            m_array[i] = e;

        return res;       
    }

    int length() const
    {
        return m_length;
    }
    void clear()
    {
        m_length = 0;
    }

    // 顺序存储线性表 提供数组的访问方式
    T& operator[] (int i)
    {
        if((i<m_length)&&(i>=0))
        {
            return m_array[i];
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Index out of bound.");
        }
    }

    T operator[] (int i) const //const数组
    {
       return (const_cast<SeqList& >(*this))[i]; 
    }

    //空间容量
    virtual int capacity() const = 0; //子类设置空间和大小，所以容量函数也应由子类实现
};

}


#endif //__SEQLIST_H__