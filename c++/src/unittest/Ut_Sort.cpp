/*
	入口函数
 */

#include	<stdio.h>
#include "../../include/Ut_Sort.h"
// ----------------------------------

int test()
{
	printf("\n  ** test()\n\n");
	return 0;	
}

static void swap(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void SelectSort(int k[], int len)
{
	int min = 0;
	for(int i=0; i<len; i++)
	{
		min = i;
		for(int j=i+1; j<len-1; j++)
		{
			if(k[j] < k[min])
			{
				min = j;
			}
		}
		if(min != i)
			swap(k[i],k[min]);
	}
}

void InsertSort(int k[], int len)
{
	int i,j,g;
	//为a[i]在前面的a[0...i-1]有序区间中找一个合适的位置
	for(i=1; i<len-1;i++)
	{
		for(j=0; j<i-1; j++)
		{
			if(k[i] > k[j]) break;
		}

		//找到合适的位置插入 
		if(j != i-1)
		{
			int temp = k[i];
			for(g=i-1; g>j; g--)
			{
				a[g+1] = a[j];
			}
			a[g+1] = temp;
		}
	}

}

void BubbleSort(int k[], int len)
{
	int i,j;
	for(i=0; i<len-1; i++)
	{
		for(j=0, j<len-1-i; j++)  //比较到尾巴，下次比较尾巴变小
		{
			if(k[j+1] < k[j])
			{
				swap(k[j+1],k[j]);
			}
		}
	}
}

static void find_array_central_guard(int *array, int left, int right)
{
    int& key = array[right];
    while(left < right)
    {
        while(left < right && array[left] <= key)
        {
            ++left;
        }
        while(left < right && array[right] >= key)
        {
            --right;
        }
        swap(array[left],array[right]);
    }
    swap(array[left],key);
    return left;
}

void QuickSort(int k[], int left, int right)
{
	if(k == NULL || left < 0 || right < 0)
	{
		return;
	}
	if(left >= right) return;

	int guard = find_array_central_guard(k, left, right); //寻找哨兵位置
	QuickSort(k, left, guard-1);
	QuickSort(k, guard+1, right);
}

static void Merge(int a[], int p, int q, int r) 
{
	//n1和n2分别表示左边序列和右边序列的长度。左边从p开始包括q，右边从q+1开始
	int n1 = q-p+1;
	int n2 = r-q;
	int L[] = new int[n1];
	int R[] = new int[n2];
	//k用来表示当前遍历的数组a的索引
	int i=0,j=0,k=0;
	//分别给L和R赋值
	for(i=0,k=p; i<n1; i++,k++)
	{
		L[i] = a[k];
	}
	//从右边开始
	for(j=0,k=q+1; j<n2; j++,k++)
	{
		R[j] = a[k];
	}
	//比较大小,从小到大排列
	for(i=0,j=0,k=p; i<n1&&j<n2; k++)
	{
		if(L[i] > R[j]){
			a[k] = R[j];
			j++;
		}else{
			a[k] = L[i];
			i++;
		}
	}
	//for
	//将两个数组中剩下的数放到a中
	if(i<n1)
	{
		for(j=i; j<n1; j++,k++)
		{
			a[k] = L[j];
		}
	}
	if(j<n2)
	{
		for(i=j; i<n2; i++,k++)
		{
			a[k] = R[i];
		}	
	}
}
void MergeSort(int k[], int left, int right)
{
	if(k == NULL || left < 0 || right < 0)
	{
		return;
	}
	int mid = (left + right) >> 2;

	MergeSort(k, left, mid);
	MergeSort(k, mid + 1, right);
	Merge(k,left, mid, right);  
}