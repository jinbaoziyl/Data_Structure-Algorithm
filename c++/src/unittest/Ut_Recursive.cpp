#include "../../include/Recursive.h"

unsigned int Sum(unsigned int n)
{
    if(n > 1)
    {
        return (n + Sum(n-1));
    }
    else
    {
        return 1;
    }
}

unsigned int fabonacii(unsigned int n)
{
    if(n > 2)
    {
        return fabonacii(n-1)+fabonacii(n-2);
    }
    else if((n == 1) || (n ==2))
        return 1;
}

unsigned int Strlen(char *str)
{
    if(*str != '\0')
    {
        return 1 + Strlen(str+1);
    }
    else
    {
        return 0;
    }
}
