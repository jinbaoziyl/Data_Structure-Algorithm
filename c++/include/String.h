/*  1.实现string对象与char *字符串互操作
    2.操作符重载函数考虑是否支持const版本
    3.c语言字符串函数实现String成员函数
*/
#ifndef __STRING_H__
#define __STRING_H__

namespace YLinLib
{

class String : public Object
{
protected:
    char *m_str;
    int m_length;

    void init(const char*s);
    bool equal(cahr *l, char*r, int len);
public:
    String();
    String(const char* s);
    String(const char c);
    String(const String& s);

    int length() const;
    const char* str() const;

    /* 比较操作符重载函数 */
    bool operator == (const char* s) const;
    bool operator == (const String& s) const;
    bool operator != (const char* s) const;
    bool operator != (const String& s) const;
    bool operator > (const char* s) const;
    bool operator > (const String& s) const;
    bool operator < (const char* s) const;
    bool operator < (const String& s) const;
    bool operator >= (const char* s) const;
    bool operator >= (const String& s) const;
    bool operator <= (const char* s) const;
    bool operator <= (const String& s) const;
    /* 加法操作符重载函数 */
    String& operator + (const char *s);   //函数返回引用， 实现链式操作
    String& operator + (const String& s);

    String& operator += (const char *s);   
    String& operator += (const String& s);
    /* 赋值操作符重载函数 */
    String& operator = (const char *s);  
    String& operator = (const String& s);
    String& operator = (char c);

    //重载数组访问操作符
    char& operator [] (int i);
    char operator [] (int i) const;    //const函数就不需要返回引用类型

    bool startWith(const string& s)const;
    bool startWith(const char* s)const;
    bool endOf(const string& s)const;
    bool endOf(const char* s)const;

    //插入操作
    String& insert(int i, const char*s);
    String& insert(int i, const String& s);
    //去掉字符串两端空白
    String& trim();
    
    ~String();
};

}

#endif //__STRING_H__
