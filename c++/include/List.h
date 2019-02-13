/*  线性表： 具有相同类型的n(>=0)个数据元素的有限序列
*        (a0, a1, a2,...,an)   ai是表项   n表示长度
*/
#ifndef __LIST_H__
#define __LIST_H__

namespace YLinLib
{

template <typename T>
class List : public Object  //抽象类
{
public：
    virtual bool insert(int i, const T& e) = 0;
    virtual bool remove(int i) = 0; 
    virtual bool get(int i, const T& e) const= 0;
    virtual bool set(int i, const T& e) = 0;

    virtual int length() const= 0;
    virtual void clear() = 0;
};

}

#endif //__LIST_H__