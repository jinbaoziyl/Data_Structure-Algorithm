#ifndef __STATIC_ARRAY_H__
#define __STATIC_ARRAY_H__

namespace YLinLib
{
 template <typename T, int N>
 class StaticArray : public Array<T>
 {
protected:
    T m_space[N];

public:
    StaticArray()
    {
        this->m_array = m_space;
    }

    StaticArray(const StaticArray<T, N>& obj)
    {
        this->m_array = m_space;
        if(N == obj.length())
        {
            for(int i=0; i<length(); i++)
            {
                m_space[i] = obj.m_space[i];
            }
        }
        else
        {
            cout << "No Valid Array to copy..." << endl;
        } 
    }

    StaticArray<T, N>& operator= (const StaticArray<T, N>& obj)
    {
        if(N == obj.length())
        {
            if(this != &obj)
            {
                for(int i=0; i<length(); i++)
                {
                    m_space[i] = obj.m_space[i];
                }        
            }
        }

        return *this;
    }

    int length() const
    {
        return N;
    }
 };

} // YLinLib

#endif //__STATIC_ARRAY_H__