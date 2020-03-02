#include "../../include/Object.h"

namespace YLinLib
{

void* Object::operator new(size_t size) throw()
{
    return malloc(size);
}

void Object::operator delete(void *p)
{
    free(p);
}

void* Object::operator new[](size_t size) throw()
{
   return malloc(size); 
}

void Object::operator delete[](void *p)
{
    free(p);
}

Object::~Object() {}

}