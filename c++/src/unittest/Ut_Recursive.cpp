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


//单链表的转置 伪代码
Node *reverse(Node *list)
{
    if( (list == NULL) || (list->next == NULL) )
    {
        return list;
    }
    else
    {
        Node *guard = list->next;
        Node *ret = reverse(list->next);

        guard->next = list;
        list->next = NULL;

        return ret;
    }
}

//单向排序链表的合并 伪代码
Node* merge(Node* list1, Node* list2)
{
    if(list1 == NULL)
    {
        return list2;
    }
    else if(list2 == NULL)
    {
        return list1;
    }
    else if(list1->value < list2->value)
    {
        Node* list1_ = list1->next;
        Node* list = merge(list1_, list2);

        list1->next = list;

        return list1;
    }
    else
    {
        Node* list2_ = list2->next;
        Node* list = merge(list1, list2_);

        list2->next = list;

        return list2;       
    }
}

//汉偌塔问题
void HanoiTower(int n, char a, char b,char c)  // a==>src  b==>middle c==>dest
{
    if(n == 1)
    {
        cout << a << "-->" << c << endl;
    }
    else
    {
        HanoiTower(n-1, a, c, b);
        HanoiTower(1, a, b, c);
        HanoiTower(n-1, b, a, c);
    }
}

//全排列问题
void permutation(char *s, char* e)
{
    if(*s == '\0')
    {
        cout << e << endl;
    }
    else
    {
        int len = strlen(s);

        for(int i=0; i<len; i++)
        {
            if(i==0 || (s[0]!=s[i]))
            {
            swap(s[0],s[i]);
            permutation(s+1, e)
            swap(s[0],s[i]);
            }
        }
    }
}

// 回溯算法，经典问题: 八皇后问题
void findQueen(int row)
{
    if(row > 7)
    {
        total++;       //打印解法总数
        printQueens(); //打印八皇后的解
        return;
    }

    for(int column=0; column<8; column++)  //回溯列，递归下一行
    {
        if(check(row, column))   //check()函数判断当前位置能否放下皇后
        {
            arry[row][column] = 1;
            findQueen(row+1);
            arry[row][column] = 0;  //递归下一行返回的情况，只有:行还没到7行，但是已经放不下皇后。 清零的目的: 避免脏数据干扰(它只有在皇后摆不下去的时候会执行清0的动作)
        }
    }
}