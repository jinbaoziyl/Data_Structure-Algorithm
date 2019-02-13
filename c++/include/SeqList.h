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
    bool insert(int i, const T& e);
    bool remove(int i); 
    bool get(int i, const T& e) const;
    bool set(int i, const T& e);

    int length() const;
    void clear();

    // 顺序存储线性表 提供数组的访问方式
    T& operator[] (int i);
    T  operator[] (int i) const;  //const数组

    //空间容量
    virtual int capacity() const = 0; //子类设置空间和大小，所以容量函数也应由子类实现
};

}


#endif //__SEQLIST_H__