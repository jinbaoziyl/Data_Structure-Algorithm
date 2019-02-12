#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

namespace YLinLib
{
class Exception
{
protected:
    char *m_message;
    char *m_location;

    void init(const char* message, const char* file, int line);
public:
    Exception(const char* message);
    Exception(const char* file, int line);
    Exception(const char* message, const char* file, int line);

    Exception(const Exception& e);   
    Exception& operator= (const Exception& e);

    virtual const char *message() const;
    virtual const char *location() const;

    virtual ~Exception() = 0;   //表明是抽象基类, 纯虚函数的析构函数一般都是需要实现的，父类才能跟着释放内存
};

}

#endif