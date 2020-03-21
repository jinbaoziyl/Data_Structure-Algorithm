import random
def BubbleSort(arr):
    n = len(arr)
    changed = True
    # 遍历每个元素
    if changed == True:  # 如果一次冒泡过程无交换，则已经拍好序
        for i in range(n):
            changed = False
            # 后面的已经排好序
            for j in range(n-1-i):
                if arr[j] > arr[j+1]:
                    arr[j], arr[j+1] = arr[j+1], arr[j]
                    changed = True

def InsertionSort(arr):
    n = len(arr)

    for i in range(1, n): #从
        # 内循环
        for j in range(i-1, -1, -1):
            if arr[j+1] < arr[j]:  #当前的值和后面一个值比较
                arr[j+1], arr[j] = arr[j], arr[j+1]

# 合并两个已排序数组, 成一个排序数组
def merge(arr, lo, mid, hi):
    arr_cp = arr.copy()
    i, j = lo, mid+1

    for idx in range(lo, len(arr)):
        if i > mid:
            arr[idx] = arr_cp[j]
            j += 1
        elif j > hi:
            arr[idx] = arr_cp[i]
            i += 1
        elif arr_cp[i] > arr_cp[j]:
            arr[idx] = arr_cp[j]
            j += 1
        else:
            arr[idx] = arr_cp[i]
            i += 1

def MergeSort(arr, lo, hi):
    # 数组合法性判断和递归结束条件
    if lo >= hi:  
        return
    mid = int(lo + (hi - lo)/2)  #一定要申明int类型，否则可能会报错

    MergeSort(arr, lo, mid)
    MergeSort(arr, mid + 1, hi)
    merge(arr, lo, mid, hi)


def partition(arr, lo, hi): 
    pivot = random.randrange(lo, hi+1)
    # pivot = hi
    arr[pivot], arr[hi] = arr[hi], arr[pivot] 

    i = lo
    # j变量遍历每个元素
    for j in range(lo, hi+1):
        if arr[j] < arr[hi]:
            # i变量是小于pivot的索引，离j最近的数
            arr[i], arr[j] = arr[j], arr[i] 
            i += 1
    arr[i], arr[j] = arr[j], arr[i] 
    return i

def QuickSort(arr, lo, hi):
    #判断是否只有一个元素， 递归结束条件
    if lo >= hi:
        return 
    guard = partition(arr, lo, hi)
    QuickSort(arr, lo, guard-1)
    QuickSort(arr, guard+1, hi)

arr = [64, 34, 25, 12, 22, 11, 90]
# arr = [2, 70, 80, 3, 6, 8]

# BubbleSort(arr)
# InsertionSort(arr)
# MergeSort(arr, 0, len(arr)-1)
QuickSort(arr, 0, len(arr)-1)
for i in range(len(arr)):
    print("%d" %arr[i])


