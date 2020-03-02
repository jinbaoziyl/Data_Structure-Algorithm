/* 顶层父类：
*      1.统一动态内存申请， 在堆中创建子类对象，失败时不抛出异常
*      2.定义为纯虚父类， 所有子类都能进行动态类型识别
*/
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <cstdlib>
namespace YLinLib
{

class Object
{
public:
    void* operator new(size_t size) throw(); //不抛出异常
    void operator delete(void *p);
    
    void* operator new[](size_t size) throw(); //不抛出异常
    void operator delete[](void *p);

    virtual ~Object() = 0;
};

}

#endif //__OBJECT_H__