#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__
#include "Object.h"

namespace YLinLib
{
#define THROW_EXCEPTION(e,m) (throw e(m, __FILE__, __LINE__))

class Exception: public Object
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

    virtual ~Exception();   //表明是抽象基类, 纯虚函数的析构函数一般都是需要实现的，父类才能跟着释放内存
};

class NullPointerException: public Exception
{
public:
    NullPointerException(const char* message, const char* file, int line):Exception(message, file, line) {}
    NullPointerException(const char* message):Exception(message) {}
    NullPointerException(const char* file, int line):Exception(file, line) {}
     
    NullPointerException(const NullPointerException& e):Exception(e) {}

    NullPointerException& operator= (const NullPointerException& e)
    {
	Exception::operator= (e);
	return *this;
    }
};

class IndexOutOfBoundsException: public Exception
{
public:
    IndexOutOfBoundsException(const char* message, const char* file, int line):Exception(message, file, line) {}
    IndexOutOfBoundsException(const char* message):Exception(message) {}
    IndexOutOfBoundsException(const char* file, int line):Exception(file, line) {}
     
    IndexOutOfBoundsException(const IndexOutOfBoundsException& e):Exception(e) {}

    IndexOutOfBoundsException& operator= (const IndexOutOfBoundsException& e)
    {
	Exception::operator= (e);
	return *this;
    }
};


class NoEnoughMemoryException: public Exception
{
public:
    NoEnoughMemoryException(const char* message, const char* file, int line):Exception(message, file, line) {}
    NoEnoughMemoryException(const char* message):Exception(message) {}
    NoEnoughMemoryException(const char* file, int line):Exception(file, line) {}
     
    NoEnoughMemoryException(const NoEnoughMemoryException& e):Exception(e) {}

    NoEnoughMemoryException& operator= (const NoEnoughMemoryException& e)
    {
	Exception::operator= (e);
	return *this;
    }
};


class InvalidParameterException: public Exception
{
public:
    InvalidParameterException(const char* message, const char* file, int line):Exception(message, file, line) {}
    InvalidParameterException(const char* message):Exception(message) {}
    InvalidParameterException(const char* file, int line):Exception(file, line) {}
     
    InvalidParameterException(const InvalidParameterException& e):Exception(e) {}

    InvalidParameterException& operator= (const InvalidParameterException& e)
    {
	Exception::operator= (e);
	return *this;
    }
};

}

#endif
