#include "Exception.h"
#include <cstring>
#include <iostream>

namespace YLinLib
{
class ArithmeticException: public Exception
{
public:
    ArithmeticException(const char* message, const char* file, int line):Exception(message, file, line) {}
    ArithmeticException(const char* message):Exception(message) {}
    ArithmeticException(const char* file, int line):Exception(file, line) {}
     
    ArithmeticException(const ArithmeticException& e):Exception(e) {}

    ArithmeticException& operator= (const ArithmeticException& e)
    {
	Exception::operator= (e);
	return *this;
    }

};

}
