#include "../../include/String.h"
#include <cstring.h>

using namespace std;


namespace YLinLib
{

void String::init(const char*s)
{
    m_str = strdup(s);

    if(m_str != NULL)
    {
        m_length = strlen(s);
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException, "No memory to alloc...");
    }
}

String::String()
{
    init("");
}

String::String(const char* s)
{
    init(s ? s : "");
}

String::String(const String& s)
{
    init(s.m_str);
}

String::String(const char c)
{
    char s[] = {c,"\0"};
    init(s);
}

int String::length() const
{
    return m_length;
}

const char* String::str() const
{
    return m_str;
}

bool String::operator == (const char* s) const
{
    return strcmp(m_str, s ? s : "");
}

bool String::operator == (const String& s) const
{
    return strcmp(m_str, s.m_str);
}

bool String::operator != (const char* s) const
{
    return !(*this == s);
}

bool String::operator != (const String& s) const
{
    return !(*this == s);
}

bool String::operator > (const char* s) const
{
    return (strcmp(m_str, s ? s : "") > 0);
}

bool String::operator > (const String& s) const
{
    return (strcmp(m_str, s.m_str) > 0);
}

bool String::operator < (const char* s) const
{
    return (strcmp(m_str, s ? s : "") < 0);
}

bool String::operator < (const String& s) const
{
    return (strcmp(m_str, s.m_str) < 0);  
}

bool String::operator >= (const char* s) const
{
    return (strcmp(m_str, s ? s : "") > 0);
}

bool String::operator >= (const String& s) const
{
    return (strcmp(m_str, s,m_str) > 0);
}

bool String::operator <= (const char* s) const
{
    return (strcmp(m_str, s ? s : "") <= 0);
}

bool String::operator <= (const String& s) const
{
    return (strcmp(m_str, s,m_str) <= 0);
}

String& String::operator + (const char *s)
{
    String ret;
    int len = strlen(s ? s : "") + m_length;
    char *str = reinterpret_cast<char*>(malloc(len + 1));
    if(str)
    {
        strdup(str, m_str);
        strcat(str, s?s:"");

        free(ret.m_str);
        ret.m_length = len;
        ret.m_str;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException, "No memory to alloc...");
    }
    return ret;
}

String& String::operator + (const String& s)
{
    return (*this + s.m_str);
}

String& String::operator += (const char *s)
{
    return (*this = *this + s);   //用到赋值操作符，所以一定需要重载
}

String& String::operator += (const String& s)
{
    return (*this = *this + s.m_str);
}

String& String::operator = (const char *s)
{
    if(m_str != s)
    {
        char *str = strdup(s);
        if(str)
        {
            free(m_str);
            m_str = str;
            m_length = strlen(str);
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to alloc...");
        }
    }

    return *this;
} 

String& String::operator = (const String& s)
{
    return (*this = s.m_str);
}

String& String::operator = (char c)
{
    char str[] = {c, '\0'}

    return (*this = str);
}

char& String::operator [] (int i)
{
    int ret = (i>=0) && (i<m_length);

    if(ret)
    {
        return m_str[i];
    }
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException, "out of bound..."); 
    }
}

char String::operator [] (int i) const
{
    return (const_cast<String&>(*this))[i];
}


bool String::equal(cahr *l, char*r, int len)
{
    int ret = true;
    for(int i=0; i<len && ret; i++)
    {
        ret = (l[i]==r[i]) && ret;
    }

    return ret;
}

bool String::startWith(const string& s)const
{
    return startWith(s.m_str);
}

bool String::startWith(const char* s)const
{
    bool ret = (s!=NULL);
    if(ret)
    {
        int len = strlen(s);
        ret = (len < m_length) && equal(m_str,s, len);
    }

    return ret;
}

bool String::endOf(const string& s)const
{
    return endOf(s.m_str);
}

bool String::endOf(const char* s)const
{
    bool ret = (s!=NULL);
    if(ret)
    {
        int len = strlen(s);
        char *str = m_str + (m_length-len);
        ret = (len < m_length) && equal(str,s, len);
    }

    return ret;  
}

String& String::insert(int i, const char*s)
{
    bool ret = (i >= 0) && (i < m_length);
    if(ret)
    {
        if(s != NULL && s[0] != '\0')
        {
            int len = strlen(s);
            char* str = reinterpret_cast<char*>(malloc(len + m_length + 1));

            if(str)
            {
                strncpy(str, m_str, i);
                strncpy(str + i, s, len);
                strncpy(str + i + len, m_str+i, m_length-i);
                str[m_length + len] = '\0';

                free(m_str);

                m_str = str;
                m_length = m_length + len;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to alloc...");
            }
        }
    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException, "invalid operation..."); 
    }
}

String& String::insert(int i, const String& s)
{
    return insert(i,s.m_str);
}

String& String::trim()
{
    int b = 0;
    int a = m_length - 1;

    while(m_str[b] == ' ') b++;
    while(m_str[a] == ' ') a--;

    if(b == 0)
    {
        m_str[a+1] = '\0';
    }
    else
    {
        for(int i=0,j=b; j<=e; i++,j++)
        {
            m_str[i] = m_str[j];
        }

        m_str[a - b + 1] = '\0';
        m_length = a - b + 1;
    }
}

String::~String()
{
    free(m_str);
}

}