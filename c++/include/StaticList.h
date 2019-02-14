/*  1.使用原生数组作为顺序空间
*   2.使用模板参数 指定存储的大小
*/
#ifndef __STATIC_LIST_H__
#define __STATIC_LIST_H__

namespace YLinLib
{

template <typename T, int N>
class StaticList : public SeqList<T>
{
protected:
    T m_space[N];
public:
    StaticList()
    {
        this->m_array = m_space;
        this->m_length = 0;
    }
    int capacity() const
    {
        return N;
    }
};

}

#endif //__STATIC_LIST_H__